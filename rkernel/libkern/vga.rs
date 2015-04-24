// VGA library for BIOS-mode
use prelude::*;
use core::fmt;
use core::intrinsics::{volatile_store, volatile_load};

#[repr(u8)] #[derive(Clone, Copy, PartialEq, Eq)]
pub enum VgaColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGrey = 7,
    DarkGrey = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightBrown = 14,
    White = 15
}

#[repr(u16)]
#[packed]
#[derive(Clone, Copy, PartialEq, Eq)]
pub struct VgaEntry {
    pub attr: u8,
    pub ch: u8,
}

impl fmt::Display for VgaEntry {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // 8 bit color, 8 bit char -> 16bit VGA Entry
        write!(f, "{}",  ((self.attr as u16) << 8) | self.ch as u16)
    }
}

//= 0xb8000 as *mut VgaEntry
// Screen information
const VGA_HEIGHT: isize = 25;
const VGA_WIDTH: isize = 80;
const LAST_OFFSET: isize = VGA_HEIGHT * VGA_WIDTH - 1;


// Cursor positioning
pub struct VgaFrameBuffer {
    screen: *mut VgaEntry,
    offset: isize,
    pub fg: VgaColor,
    pub bg: VgaColor
}

impl VgaFrameBuffer {
    pub fn new() -> VgaFrameBuffer {
        VgaFrameBuffer {screen: 0xb8000 as *mut VgaEntry,
                        offset: 0,
                        fg: VgaColor::Green,
                        bg: VgaColor::Black,
        }
    }

    // Clear the VGA Frame Buffer
    pub fn clear(&mut self) {
        let empty = VgaEntry {attr: 0, ch: 0};
        for i in 0..VGA_HEIGHT {
            for j in 0..VGA_WIDTH {
                let offs = i * VGA_WIDTH + j;
                unsafe {
                    volatile_store(self.screen.offset(offs), empty)
                }
            }
        }
        self.offset = 0;
    }

    // Scroll the VGA Frame Buffer by one line
    pub fn scroll(&mut self) {
        for i in 1..VGA_HEIGHT {
            for j in 0..VGA_WIDTH {
                let offs = i * VGA_WIDTH + j;
                let prior = (i-1)* VGA_WIDTH + j;
                unsafe {
                    let entry = volatile_load(self.screen.offset(offs));
                    volatile_store(self.screen.offset(prior), entry);
                }
            }
        }
        // Clear the final row
        let i = VGA_HEIGHT - 1;
        let empty = VgaEntry {attr: 0, ch: 0};
        for j in 0..VGA_WIDTH {
            let offs = i * VGA_WIDTH + j;
            unsafe {
                volatile_store(self.screen.offset(offs), empty);
            }
        }
        // set the cursor back to the beginning of a row
        self.offset -= VGA_WIDTH;
    }
}

impl fmt::Write for VgaFrameBuffer {
    fn write_str(&mut self, s: &str) -> fmt::Result {
        unsafe {

        }
        Ok(())
    }
    fn write_char(&mut self, c: char) -> fmt::Result {
        let colr = (self.fg as u8) | ((self.bg as u8) << 4);
        let entry = VgaEntry{attr: colr, ch: c as u8};
        unsafe {
            volatile_store(self.screen.offset(self.offset), entry);
        }
        self.offset += 1;
        if self.offset > LAST_OFFSET {
            self.scroll();
        }
        Ok(())
    }
}

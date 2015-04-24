/*
 * Rust BareBones OS
 * - By John Hodge (Mutabah/thePowersGang)
 *
 * arch/x86/x86_io.rs
 * - Support for the x86 IO bus
 *
 * == LICENCE ==
 * This code has been put into the public domain, there are no restrictions on
 * its use, and the author takes no liability.
 */


#[inline(always)]
pub unsafe fn inb(port: u16) -> u8 {
    let data: u8;
    asm!("inb $1,$0" : "={al}" (data) : "{dx}" (port) :: "volatile");
    data
}

#[inline(always)]
pub unsafe fn outb(port: u16, data: u8) {
    asm!("outb $0,$1" :: "{al}" (data), "{dx}" (port) :: "volatile");
}


/// Write a word (16-bits) to the specified port
pub unsafe fn outw(port: u16, val: u16)
{
    asm!("outw $1,$0" : : "{dx}"(port), "{ax}"(val) :: "volatile");
}

/// Read a word (16-bits) from the specified port
pub unsafe fn inw(port: u16) -> u16
{
    let data : u16;
    asm!("inw $1,$0" : "={ax}"(data) : "{dx}"(port) :: "volatile");
    data
}

/// Write a long/double-word (32-bits) to the specified port
pub unsafe fn outl(port: u16, val: u32)
{
    asm!("outl $1, $0" : : "{dx}"(port), "{eax}"(val) :: "volatile");
}

/// Read a long/double-word (32-bits) from the specified port
pub unsafe fn inl(port: u16) -> u32
{
    let ret : u32;
    asm!("inl $1,$0" : "={eax}"(ret) : "{dx}"(port) :: "volatile");
    ret
}

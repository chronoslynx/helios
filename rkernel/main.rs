/*
 * Rust BareBones OS
 * - Originally By John Hodge (Mutabah/thePowersGang)
 * - Now by Tim Swihart (chronoslynx/chronon)
 *
 * main.rs
 * - Top-level file for kernel
 *
 * This code has been put into the public domain, there are no restrictions on
 * its use, and the author takes no liability.
 */
#![feature(no_std)]     //< unwind needs to define lang items
#![feature(lang_items)] //< unwind needs to define lang items
#![feature(asm)]        //< As a kernel, we need inline assembly
#![feature(core)]       //< libcore (see below) is not yet stablized
#![feature(intrinsics)] //< volatile_{store,load}
#![no_std]              //< Kernels can't use std

// Load libcore (it's nice and freestanding)
// - We want the macros from libcore
#[macro_use]
extern crate core;

mod std {
    /// A dummy 'std' module to work around a set of issues in rustc
    // #18491 - write!() expands to std::fmt::Arguments::new
    pub use core::fmt;
    // #16803 - #[derive] references std::cmp
    pub use core::cmp;
    // #21827 - Slicing syntax references std::ops
    pub use core::ops;
    // #21827 - Loops reference std
    pub use core::iter;
    pub use core::option;
    // #16803 - Derive references marker/ops
    pub use core::marker;
}

/// Macros, need to be loaded before everything else due to how rust parses
#[macro_use]
pub mod macros;

// Our own prelude
mod prelude;

// Achitecture-specific modules
#[cfg(target_arch="x86_64")] #[path="arch/amd64/mod.rs"]
pub mod arch;
#[cfg(target_arch="x86")] #[path="arch/x86/mod.rs"]
pub mod arch;

pub mod freestanding;
mod logging;
mod vga;

// Kernel entrypoint
#[lang="start"]
#[no_mangle]
pub fn kmain()
{
    klog!("Hello world!");
    loop {}
}

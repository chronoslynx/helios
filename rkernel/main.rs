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
#![no_std]              //< Kernels can't use std

// Load libcore (it's nice and freestanding)
// - We want the macros from libcore
#[macro_use]
extern crate core;

#[macro_use]
extern crate kern;

/// libkernel code
use kern::*;

// Kernel entrypoint
#[lang="start"]
#[no_mangle]
pub fn kmain()
{
    log!("Hello world! 1={}", 1);
    loop {}
}

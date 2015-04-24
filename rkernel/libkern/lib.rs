#![feature(no_std)]
#![no_std]
#![crate_id = "rlibk#0.1"]
#![crate_type = "staticlib"]
#![feature(asm, intrinsics)]
#![feature(core)]
#![feature(lang_items)]
/// rlibk - Rust kernel library

#[macro_use]
extern crate core;

/// Macros, need to be loaded before everything else due to how rust parses
#[macro_use]
pub mod macros;

// Our own prelude
pub mod prelude;

// Achitecture-specific modules
#[cfg(target_arch="x86_64")] #[path="arch/amd64/mod.rs"]
pub mod arch;
#[cfg(target_arch="x86")] #[path="arch/x86/mod.rs"]
pub mod arch;

pub mod freestanding;
pub mod logging;
pub mod std;
pub mod vga;

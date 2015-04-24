#![feature(no_std)]  // no std, we're runnning named here
#![feature(core)]
#![no_builtins]      // we're defining the builtins, don't optimize them away!

extern crate core;

#[no_mangle]
pub unsafe extern fn memcpy(dst: *mut u8, src: *const u8,
                            n: usize) -> *mut u8 {
    let mut i = 0;
    while i < n {
        *dst.offset(i as usize) = *src.offset(i as isize);
        i += 1;
    }
    dst
}

#[no_mangle]
pub unsafe extern fn memmove(dst: *mut u8, src: *const u8,
                             n: usize) -> *mut u8{

}

#[no_mangle]
pub unsafe extern fn memcmp(dst: *mut u8, src: *const u8,
                            n: usize) -> *mut u8{

}

#[no_mangle]
pub unsafe extern fn memset(dst: *mut u8, to: u8,
                            n: usize) -> *mut u8{

}

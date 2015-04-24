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

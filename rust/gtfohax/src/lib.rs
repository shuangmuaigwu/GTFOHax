//! Rust scaffold for the GTFOHax refactor targeting Windows 11 x64.

const TARGET_PLATFORM: &str = "x86_64-pc-windows-msvc";

/// Returns the intended target triple for the Rust refactor.
pub fn target_triple() -> &'static str {
    TARGET_PLATFORM
}

/// Human-readable banner that can be reused by future injector/DLL entry points.
pub fn banner() -> String {
    format!("GTFOHax Rust core (target: {})", TARGET_PLATFORM)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn target_triple_is_windows_x64() {
        assert_eq!(target_triple(), "x86_64-pc-windows-msvc");
    }

    #[test]
    fn banner_contains_target() {
        let banner = banner();
        assert!(banner.contains(target_triple()));
        assert!(banner.starts_with("GTFOHax Rust core"));
    }
}

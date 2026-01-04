#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{generate_context, generate_handler, Manager};

#[tauri::command]
fn get_banner() -> String {
    let banner = gtfohax::banner();
    if banner.chars().any(|c| c.is_control()) {
        "GTFOHax Rust core".to_string()
    } else {
        banner
    }
}

fn main() {
    tauri::Builder::default()
        .invoke_handler(generate_handler![get_banner])
        .run(generate_context!())
        .unwrap_or_else(|e| panic!("failed to run GTFOHax UI: {e}"));
}

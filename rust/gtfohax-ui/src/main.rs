#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{generate_context, generate_handler, Manager};

#[tauri::command]
fn get_banner() -> String {
    gtfohax::banner()
}

fn main() {
    tauri::Builder::default()
        .invoke_handler(generate_handler![get_banner])
        .run(generate_context!())
        .expect("error while running tauri application");
}

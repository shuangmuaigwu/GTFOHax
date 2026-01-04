#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use tauri::{generate_context, generate_handler, Manager};

#[tauri::command]
fn get_banner() -> String {
    gtfohax::banner()
}

fn main() {
    tauri::Builder::default()
        .invoke_handler(generate_handler![get_banner])
        .setup(|app| {
            let handle = app.handle();
            let _ = handle.create_window(
                "main",
                tauri::WindowUrl::App("index.html".into()),
                |builder, _attrs| builder.title(gtfohax::banner()),
            );
            Ok(())
        })
        .run(generate_context!())
        .expect("error while running tauri application");
}

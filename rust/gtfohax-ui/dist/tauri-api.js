export async function invoke(command, args) {
  const tauri = window.__TAURI__;
  if (tauri?.core?.invoke) {
    return tauri.core.invoke(command, args);
  }
  throw new Error("Tauri API is not available in this context");
}

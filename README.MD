# Bluetooth Macrokeys ESP32 JC2432W28C Guition implementation

## Features 
 - EEZ studio -> LVGl native cpp implementation

 - BleKeyboard library (uses NimBLE so save RAM)

 - Loads json profiles from Sd card by reading macrokeys/config folder

 - Two Tabbed 3x2 Custom buttons, button box

- Deserialises json and button map from config

## Flow diagram
```mermaid
sequenceDiagram
    participant User
    participant ProfileSelectorView
    participant RollerElement
    participant OkButton
    participant configReader
    participant MainPage
    participant Vars
    participant Actions

    User->>ProfileSelectorView: Load View
    ProfileSelectorView->>configReader: OnLoad()
    configReader->>configReader: ReadSd()
    configReader->>configReader: Read folder config for JSON configs
    configReader-->>ProfileSelectorView: Return JSON configs
    ProfileSelectorView->>RollerElement: Populate dynamically

    User->>OkButton: Press OK
    OkButton->>ProfileSelectorView: OnOkPressed()
    ProfileSelectorView->>configReader: ChangeScreen(MainPage)
    OkButton-->>Actions: Switch to MainPage (dotted)
    configReader->>configReader: Load JSON file path
    configReader->>configReader: Deserialize JSON object
    configReader->>Actions: Pass handler with JSON data
    
    Actions->>Vars: Populate with labels and key bindings from JSON
    Actions->>MainPage: Set labels with populated data
    Actions->>MainPage: Switch to MainPage

    MainPage->>MainPage: OnMainPageLoad()
    MainPage->>Vars: Get label mappings
    MainPage->>MainPage: Populate label elements
    MainPage->>Actions: Map button press
```

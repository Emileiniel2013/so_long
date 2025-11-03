# so_long

**so_long** is a small 2D game written in **C** using the **MiniLibX** graphics library.  
It serves as an introduction to fundamental game development concepts such as rendering, event handling, and map parsing.

The game reads a `.ber` map file and dynamically draws it to the screen.  
Your goal: collect all the cakes 🍰 and reach the exit portal — while avoiding obstacles along the way.

---

## 🎮 Features
- Dynamic 2D rendering with MiniLibX  
- Player movement and collision detection  
- Collectibles and exit portal logic  
- Custom map validation with detailed error handling  
- Real-time keyboard input and map updates per frame  
- Lightweight, single-threaded rendering loop  

---

## 🗺 Map Format

- Map files must be placed inside the `maps/` directory  
- File extension must be `.ber`  
- Must include:
  - Exactly one player start position  
  - At least one collectible and one exit  
  - Walls enclosing the entire map  

If any rule is broken, the program prints a **specific custom error message**.

---

## ⚙️ How to Run

### 1. Build the project
```bash
make
```
2. Run the game
```bash
./so_long maps/example.ber
```
3. Controls
| Key               | Action                     |
| ----------------- | -------------------------- |
| **W / A / S / D** | Move up, left, down, right |
| **ESC**           | Quit the game              |

Each key press updates the player's position, removes collected items, and redraws the entire map — simulating smooth movement.
---
🎨 Customization

You can use your own textures and sprites by replacing the .xpm files in the textures/ directory.
Make sure to preserve the same file names or update the map configuration to match your new assets.
---
🧠 Technical Details

-Written in C (C99)

-Built with MiniLibX for rendering and input handling

-Single render loop architecture

-Error-safe map parsing and memory management

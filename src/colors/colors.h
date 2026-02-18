#pragma once

#include "raylib.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

#define TRANSPARENT {0,0,0,0}

using json = nlohmann::json;

struct Theme {
    Color background = (Color){21, 22, 23, 255};
    Color primary = (Color){247, 247, 247, 255};
    Color accent = (Color){146, 154, 171, 255};
    Color text = (Color){238, 238, 238, 255};
};

extern Theme current_theme;

inline Color ParseRGBA(json j) {
    return (Color){ 
        (uint8_t)j["r"], 
        (uint8_t)j["g"], 
        (uint8_t)j["b"], 
        255 // Default to fully opaque
    };
}

inline void LoadTheme(Theme *theme){
    std::ifstream f("themes/default_theme.json");
    json color = json::parse(f);
    std::cout << color["background"]["r"];
    theme->background = ParseRGBA(color["background"]);
    theme->primary = ParseRGBA(color["primary"]);
    theme->accent = ParseRGBA(color["accent"]);
    theme->text = ParseRGBA(color["text"]);
};
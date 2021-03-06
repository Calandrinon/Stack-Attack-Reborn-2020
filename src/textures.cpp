#include "textures.h"

Textures::Textures(SDL_Renderer* renderer) {
	this->renderer = renderer;	
	this->block_texture = IMG_LoadTexture(renderer, "res/block.png");
	this->crane_texture = IMG_LoadTexture(renderer, "res/crane.png");
	this->player_spritesheet= IMG_LoadTexture(renderer, "res/builder_sprite_sheet.png");
}

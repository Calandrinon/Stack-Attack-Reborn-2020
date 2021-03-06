#include "collisiondetector.h"

CollisionDetector::CollisionDetector(BlockContainer* block_container) {
	this->block_container = block_container;
}


bool CollisionDetector::player_block_collision(Player* player, Block* block) {	
	int player_left = player->get_left_side();
	int player_top = player->get_y_coordinate(); 
	int player_bottom = player_top + player->get_height(); 	
	int player_right = player->get_right_side();
		
	int block_width = block->get_width();
	int block_left = block->get_x_coordinate();	
	int block_top = block->get_y_coordinate();	
	int block_bottom = block_top + block_width;	
	int block_right = block_left + block_width;

	if (player_left < block_right && player_right > block_left && player_top < block_bottom && player_bottom > block_top)
		return true;
	return false;
}


bool CollisionDetector::check_player_collision_with_other_blocks(Player* player) {
	std::vector<Block*>::iterator block_container_it;
	std::vector<Block*>* pointer_to_container = this->block_container->get_pointer_to_container();

	for (block_container_it = pointer_to_container->begin(); block_container_it < pointer_to_container->end(); block_container_it++) {
		if (this->player_block_collision(player, (*block_container_it))) {
			return true;
		}
	}	
	
	return false;
}


bool CollisionDetector::collision_between_two_blocks(Block* first_block, Block* second_block) {	
	int first_block_left = first_block->get_x_coordinate();
	int first_block_top = first_block->get_y_coordinate(); 
	int block_width = first_block->get_width();
	int first_block_bottom = first_block_top + block_width; 	
	int first_block_right = first_block_left + block_width;
	
	int second_block_left = second_block->get_x_coordinate();	
	int second_block_top = second_block->get_y_coordinate();	
	int second_block_bottom = second_block_top + block_width;	
	int second_block_right = second_block_left + block_width;

	if (first_block_left < second_block_right && first_block_right > second_block_left && first_block_top < second_block_bottom && first_block_bottom > second_block_top)
		return true;
	return false;
}


bool CollisionDetector::bottom_side_collision_of_block_in_motion(Block* block, int x_coordinate_of_landing_position) {
	std::vector<Block*>::iterator block_container_it;
	std::vector<Block*>* pointer_to_container = this->block_container->get_pointer_to_container();

	for (block_container_it = pointer_to_container->begin(); block_container_it < pointer_to_container->end(); block_container_it++) {
		if (block == (*block_container_it))
			continue;
	
		if ((*block_container_it)->get_x_coordinate() == x_coordinate_of_landing_position) {
			if (CollisionDetector::collision_between_two_blocks(block, (*block_container_it))) {
				block->set_y_coordinate((*block_container_it)->get_y_coordinate() - block->get_width());
				return true;
			}
		}	
	}	
	
	return false;
}


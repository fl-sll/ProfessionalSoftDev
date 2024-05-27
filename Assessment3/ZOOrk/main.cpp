#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"


int main() {
    std::shared_ptr<Room> start = std::make_shared<Room>("Desa Kerinci Graveyard",
                                "You awaken amidst crumbling gravestones shrouded in mist. The air hangs heavy with the scent of incense and damp earth.\nAn unsettling silence is broken only by the chirping of crickets. An ornately carved stone gate, weathered with age, stands as the only exit.\n");

    std::shared_ptr<Room> abandoned_school = std::make_shared<Room>("Abandoned School",
                                "Vines crawl through the shattered windows of a deserted school building. Inside, desks are overturned, papers scatter\nacross the dusty floor, and a faint melody drifts from a broken record player. Cobwebs drape a bulletin board adorned with faded school photos - some faces seem to follow you with their gaze.\n");

    std::shared_ptr<Room> jungle_river = std::make_shared<Room>("Jungle River",
                                "Lush foliage and tangled vines overhang a murky river. The air is thick with the sounds of insects and the occasional\nscreech of unseen birds. A rickety wooden bridge spans the river, leading to a dense, unexplored jungle on the other side.\n");

    std::shared_ptr<Room> grandma_house = std::make_shared<Room>("Grandmother's House",
                                "A warm glow emanates from a traditional wooden house. Inside, a familiar scent of spices and simmering soup fills the\n air. An elderly woman sits rocking in a dimly lit corner, her face obscured by shadows. A sense of unease washes over you as she speaks in a raspy voice you can't quite understand.\n");
            
    std::shared_ptr<Room> warung_angker = std::make_shared<Room>("Warung Angker",
                                "A flickering neon sign advertises 'Nasi Goreng' above a dilapidated warung (food stall). Inside, empty tables and overturned\n chairs create an eerie scene. A faint sizzling sound emanates from the back, but no one seems to be around.\n");
    
    std::shared_ptr<Room> hidden_bunker = std::make_shared<Room>("Hidden Bunker",
                                "You stumble upon a concealed entrance beneath a banyan tree. Inside, a musty bunker reveals remnants of military equipment\n and flickering fluorescent lights. Strange symbols are scrawled on the walls, and a chilling voice whispers your name through a broken radio.\n");
    
    std::shared_ptr<Room> shadow_puppet_theater = std::make_shared<Room>("Shadow Puppet Theater",
                                "The air crackles with anticipation as you enter a darkened theatre. Cobwebs cling to dusty wayang (shadow puppet) figures\n depicting grotesque demons. A lone spotlight illuminates a central stage, and an unsettling feeling tells you you're not alone.\n");

    std::shared_ptr<Room> candi = std::make_shared<Room>("Candi",
                                "Moss-covered stone statues of mythical creatures guard the entrance to a crumbling Candi (Hindu temple). Strange markings\n adorn the weathered walls, depicting scenes of rituals and forgotten deities. An unsettling hum resonates within the ancient structure.\n");

    std::shared_ptr<Room> cyber_cafe = std::make_shared<Room>("Cyber Cafe",
                                "Rows of dusty computer monitors flicker with static. Abandoned keyboards and headsets litter the desks, remnants of a \nforgotten online world. A single terminal remains powered on, displaying a cryptic message in Bahasa Indonesia.\n");

    std::shared_ptr<Room> hidden_village = std::make_shared<Room>("Hidden Village",
                                "After navigating a treacherous jungle path, you emerge into a clearing revealing a hidden village. Villagers with painted\n faces go about their daily routines, seemingly oblivious to your presence. An unsettling calm hangs in the air, broken only by the rhythmic beating of drums in the distance.\n");
    
    Passage::createBasicPassage(start.get(), abandoned_school.get(), "east", true);
    Passage::createBasicPassage(start.get(), grandma_house.get(), "south", true);
    Passage::createBasicPassage(abandoned_school.get(), jungle_river.get(), "east", true);
    Passage::createBasicPassage(abandoned_school.get(), warung_angker.get(), "south", true);
    Passage::createBasicPassage(jungle_river.get(), hidden_bunker.get(), "south", true);
    Passage::createBasicPassage(grandma_house.get(), shadow_puppet_theater.get(), "east", true);
    Passage::createBasicPassage(grandma_house.get(), candi.get(), "south", true);
    Passage::createBasicPassage(shadow_puppet_theater.get(), warung_angker.get(), "east", true);
    Passage::createBasicPassage(warung_angker.get(), cyber_cafe.get(), "south", true);
    Passage::createBasicPassage(warung_angker.get(), candi.get(), "east", true);
    Passage::createBasicPassage(cyber_cafe.get(), hidden_village.get(), "east", true);
    Passage::createBasicPassage(cyber_cafe.get(), candi.get(), "west", true);
    Passage::createBasicPassage(hidden_bunker.get(), warung_angker.get(), "west", true);
    Passage::createBasicPassage(hidden_bunker.get(), hidden_village.get(), "south", true);

    ZOOrkEngine zoork(start);

    zoork.run();

    return 0;
}

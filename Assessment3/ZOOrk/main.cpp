#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include "Item.h"

int main()
{
// ROOMS
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


// PASSAGES
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

// ITEMS
    std::shared_ptr<Item> daun = std::make_shared<Item>("daun_kelor", "Daun kelor, or moringa leaves, are believed to have protective properties against evil spirits. These leaves can dispel curses and provide a shield against ghostly entities, especially for the one that jump and haunt you in every step.");
    start->addItem(daun);

    std::shared_ptr<Item> garam = std::make_shared<Item>("garam", "It is widely regarded in various cultures as a purifying substance. It is known to repel mischievous spirits and is used to cleanse spaces of malevolent entities. Those entities are small and like to steal from humans.");
    grandma_house->addItem(garam);

    std::shared_ptr<Item> holy_water = std::make_shared<Item>("air_suci", "In case you are wondering, this item proves to be  a valuable asset in going against an evil Giant Spirit which you might encounter as you go around the map.");
    warung_angker->addItem(holy_water);

    std::shared_ptr<Item> bambu = std::make_shared<Item>("bambu_kuning", " An exotic plant found in the depths of the Jungle River. Remember the unseen spirits lurking amongst the ten doors? You may want to use this sacred plant when you encounter them.");
    jungle_river->addItem(bambu);

    std::shared_ptr<Item> keris = std::make_shared<Item>("keris", "A traditional Javanese hand-crafted weapon that has been passed down across generations. This weapon symbolizes hope and courage to those who wield it. A temple guardian might be lurking anywhere waiting to strike, make sure to carry this item to battle its arsenal of mystic artillery.");
    hidden_village->addItem(keris);

// GHOSTS
    std::shared_ptr<NPC> pocong = std::make_shared<NPC>("pocong", 
    "Pocong is a ghost in Indonesian folklore known for its burial shroud. It hops around and is said to haunt the living.", 
    "Foolish mortal, you dare to disturb my restless slumber? I am cursed to wander in this shroud. Beware, for I shall haunt your every step...", 
    "daun_kelor");
    abandoned_school->addCharacter(pocong);

    std::shared_ptr<NPC> tuyul = std::make_shared<NPC>("tuyul", 
    "Tuyul is a small child-like spirit in Indonesian mythology, often depicted as a mischievous or malevolent creature used by humans to steal.", 
    "Hehe, a new face! I'm a master of mischief. Have you lost something? Perhaps I can help... for a price, but not with that grandma's stuff!", 
    "garam");
    cyber_cafe->addCharacter(tuyul);

    std::shared_ptr<NPC> genderuwo = std::make_shared<NPC>("genderuwo", 
    "Genderuwo is a Javanese mythical creature, a large, hairy humanoid that is known to terrorize people.", 
    "Human, you dare tread my domain? I am Genderuwo, those who dare to stand on my feet and bring that Holy Substance are assured to not have peace.", 
    "air_suci");
    hidden_bunker->addCharacter(genderuwo);

    std::shared_ptr<NPC> siluman = std::make_shared<NPC>("siluman", 
    "Siluman refers to shapeshifting spirits or creatures in Indonesian folklore. This creature often looks deceiving.", 
    "Ah, a visitor. Look to the left, right, front, and back. I am sure that you won't know where I'll appear next. But that sacred plant calls upon my presence. Can you trust what you see?",
    "bambu_kuning");
    shadow_puppet_theater->addCharacter(siluman);

    std::shared_ptr<NPC> hantu_penjaga = std::make_shared<NPC>("hantu_penjaga_candi", 
    "Hantu Penjaga Candi, or Temple Guardian Ghost, is believed to be a spirit that guards ancient temples, protecting sacred places from intruders.", 
    "Halt! I am the protector of these sacred grounds. State your intentions, intruder, only if you possess the ultimate weapon shall you dare to face me!!",
    "keris");
    candi->addCharacter(hantu_penjaga);

    ZOOrkEngine zoork(start);

    zoork.addNPC(pocong);
    zoork.addNPC(tuyul);
    zoork.addNPC(genderuwo);
    zoork.addNPC(siluman);
    zoork.addNPC(hantu_penjaga);

    zoork.run();

    return 0;
}
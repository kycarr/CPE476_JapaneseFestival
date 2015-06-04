#include "Shop.h"

Shop::Shop(GLuint _ShadeProg, Sound* _sound, Camera* _camera) {
    ShadeProg = _ShadeProg;
    sound = _sound;
    camera = _camera;
    curItem = 0;
    gameStart = false;
    /*tooPoor = 0.0;
    prePurch = 0.0;
    buySong = 0.0;
    buyOtft = 0.0;*/
    
    items.reserve(7);
    
    setUp();
}

Shop::~Shop() {
    for (int i = 0; i < items.size(); i++)
        delete items[i].object;
    for (int i = 0; i < misc_objects.size(); i++)
        delete misc_objects[i];
}

void Shop::setUp() {
    // Make the booth
    Object *table = new Object(shapes, materials, ShadeProg);
    table->load("cube.obj");
    table->setPos(glm::vec3(0.0, 0.0, 3.0));
    table->scale(glm::vec3(10.0f, 1.0f, 1.0f));
    table->setTexture(TEX_WOOD_DARK);
    table->setShadows(false, 0.0, 0.0);
    misc_objects.push_back(table);
    
    // Make the wall
    Object *wall = new Object(shapes, materials, ShadeProg);
    wall->load("cube.obj");
    wall->setPos(glm::vec3(0.0, 0.0, 30.0));
    wall->scale(glm::vec3(100.0f, 100.0f, 1.0f));
    wall->setTexture(TEX_WOOD_LIGHT);
    wall->setShadows(false, 0.0, 0.0);
    misc_objects.push_back(wall);
    
    // Load the songs
    vector<Song> karaoke_songs = sound->getSongs();
    for (int i = 0; i < karaoke_songs.size(); i++) {
        // Check that the song is not already free
        if (karaoke_songs[i].price != 0) {
            Item newItem;
            char* name = (char*)malloc(sizeof(char)*30);
            strcpy(name, karaoke_songs[i].song_name);
            newItem.name = name;
            //newItem.name = karaoke_songs[i].song_name;
            newItem.type = (char *)"song";
            newItem.index = i;
            
            // Song has not been purchased yet already
            if (!karaoke_songs[i].unlocked)
                newItem.price = karaoke_songs[i].price;
            else
                newItem.price = 0;
            
            Object *object = new Object(shapes, materials, ShadeProg);
            object->load((char *)"objs/screen.obj");
            object->setTexture(i + TEX_SONGS);
            object->setShadows(false, 0.0, 0.0);
            object->scale(glm::vec3(5.0, 7.0, 5.0));
            object->setPos(glm::vec3(0.0, 2.7, 3.0));
            newItem.object = object;
            
            items.push_back(newItem);
        }
    }
    
    // Load the outfits
    for (int i = TEX_GIRL_BLUE; i <= TEX_GIRL_ENDER; i++) {
        Item newItem;
        newItem.type = "outfit";
        newItem.name = "outfit";
        newItem.price = 150;
        newItem.index = i;
        
        Object *object = new Object(shapes, materials, ShadeProg);
        object->load((char *)"objs/squish_red.obj");
        object->setTexture(newItem.index);
        object->scale(glm::vec3(2.5, 2.5, 2.5));
        object->setPos(glm::vec3(0.0, 2.7, 3.0));
        newItem.object = object;
        
        items.push_back(newItem);
    }
}

void Shop::buyItem() {
    // Not enough points to buy the item
    if (global_points < items[curItem].price) {
        printf("You just remembered you're poor...\n");
        printf("Play some minigames to earn more cash!\n");
        //tooPoor = 1.0;
        sound->playIncorrectSound();
    }
    // Item was already unlocked
    else if (items[curItem].price == 0) {
        printf("You've already purchased this item.");
        //prePurch = 1.0;
        sound->playIncorrectSound();
    }
    // Buy the item
    else {
        printf("Bought %s\n", items[curItem].name);
        global_points -= items[curItem].price;
        items[curItem].price = 0;
        sound->playContactSound();
        
        // Item is a song; unlock it
        if (strcmp(items[curItem].type, SONG_TYPE) == 0) {
            printf("You can now play this song in the karaoke booth!\n");
            //buySong = 1.0;
            sound->unlockSong(items[curItem].index);
        }
        // Item is an outfit; put it on the player
        if (strcmp(items[curItem].type, OUTFIT_TYPE) == 0) {
            printf("You put on a snazzy new outfit\n");
            //buyOtft = 1.0;
            Object *player = camera->getPlayer();
            player->setTexture(items[curItem].index);
            camera->initPlayer(player);
        }
    }
}

void Shop::printInstructions() {
    ifstream instrFile;
    instrFile.open("shopinstr.txt");
    string line;
    float yPos = .5;
    float yInc;
    
    fontEngine->useFont("ostrich", 30);
    yInc = fontEngine->getTextHeight("blank") * 1.3;
    
    if (instrFile.is_open()) {
        while (getline(instrFile, line)) {
            if (line[0] == '\n') {
                yPos -= yInc;
            }
            yPos -= yInc;
            fontEngine->display(glm::vec4(1.0, 1.0, 1.0, 1.0), line.c_str(), 0-fontEngine->getTextWidth(line.c_str())/2.0, yPos);
        }
    }
    else {
        printf("file 'shopinstr.txt' was not available or could not be opened\n");
    }
}

void Shop::step(Window* window) {
    // Draw the booth
    for (int i = 0; i < misc_objects.size(); i++)
        misc_objects[i]->draw();
    
    // Draw the instructions
    if (!gameStart) {
        printInstructions();
        return;
    }
    
    // Draw the item
    items[curItem].draw();
    
    // Draw the item's information:
    // items[curItem].name
    // Cost = items[curItem].price
        // if price == 0, display "[PURCHASED]"
    float yInc, yTop = .53, yBot = -.48;

    fontEngine->useFont("ostrich", 30);
    yInc = fontEngine->getTextHeight("blank") * 1.3;

    char name[30];
    sprintf(name, "%s", items[curItem].name);
    fontEngine->display(glm::vec4(1.0, 1.0, 1.0, 1.0), name, 0-fontEngine->getTextWidth(name)/2.0, yTop);

    char price[15];
    if (items[curItem].price == 0) {
       sprintf(price, "Purchased!");
       fontEngine->display(glm::vec4(1.0, 1.0, 1.0, 1.0), price, 0-fontEngine->getTextWidth(price)/2.0, yBot);
    }
    else {
       sprintf(price, "Price: %d", items[curItem].price);
       fontEngine->display(glm::vec4(1.0, 1.0, 1.0, 1.0), price, 0-fontEngine->getTextWidth(price)/2.0, yBot);
    }
    
    /*if (tooPoor > 0.0) {
       char poor1[40];
       sprintf(poor1, "You just remembered you're poor...");
       fontEngine->display(glm::vec4(1.0, 1.0, 1.0, 1.0), poor1, 0-fontEngine->getTextWidth(poor1)/2.0, .7);
       
       char poor2[40];
       sprintf(poor2, "Play some minigames to earn more cash!");
       fontEngine->display(glm::vec4(1.0, 1.0, 1.0, 1.0), poor2, 0-fontEngine->getTextWidth(poor2)/2.0, .7-yInc);
       
       tooPoor -= window->dt;
    }
    if (prePurch > 0.0) {
    
    } 
    if (buySong > 0.0) {
    
    } 
    if (buyOtft > 0.0) {
    
    }*/
}

void Shop::prevItem() {
    if (gameStart) {
        curItem--;
        if (curItem < 0)
            curItem = items.size() - 1;
        sound->playJumpSound();
    }
}
void Shop::nextItem() {
    if (gameStart) {
        curItem++;
        if (curItem > items.size() - 1)
            curItem = 0;
        sound->playJumpSound();
    }
}
void Shop::prevCategory() {
    
}
void Shop::nextCategory() {
    
}
void Shop::selectItem() {
    buyItem();
}

/* DO NOTHING -- game does not use the mouse clicks */
void Shop::mouseClick(glm::vec3 direction, glm::vec4 point) {}
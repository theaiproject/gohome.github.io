#include <stdio.h>

/*
TO DO

1. Reconsider naming conventions - part of the v2 project
2. Rename functions - part of the v2 project
3. Reconsider decision process/frequency for uniformity
4. Consider modularity
*/

/*
V1 project
Decision based. Player picks 1 or 2 and navigates through deadly scenarios
*/

/*
V2 project
Location based. Player moves about the world by deciding which doors they will go through.
Decisions from V1 remain
*/


/*
Function Naming - V2

Each descriptor will be separated by underscores.

1. [return_type]
    Return types are a necessary function descriptor.
    There are a select number of return types.
    a. int - a decision
    b. void - a description
2. [location]
    Location describes where the function takes place, and serves to organize groups of functions.
    There are a select number of locations.
    a. office - the only location in the story thus far
3. [event]
    Event describes what is happening in the function, and serves to organize groups of functions.
    There are a select number of events.
    a. death - a player death
    b. decision - a player decision
    c. exposition - a description of the world
    d. survival - a player victory
4. [actor]
    Actor is the intacter performing an action.
    There may only be one actor at any given time, but there are an unlimited number of actors.
    ex1. player
    ex2. zombie
    ex3. train
5. [action]
    Action is a verb describing what the actor is doing to the target.
    Actions must be in the present tense.
    ex1. stabs
    ex4. ignores
6. [target]
    Target is the receiver of the action the actor is taking.
    Targets must be nouns, and are optional.
    ex1. table
    ex2. zombie
    ex3. player
*/

/* ----- Office ----- */

// Death
void reach_past_ben(); // zombie bites arm
void ben_to_hospital(); // zombie no want hospital
void jump_cubicle(); // cubicle walls flimsy
void jump_off_roof(); // 5 stories is high up
void wait_for_elevator(); // do i wait here

// Decision
int intro_decision(); // welcome to the game
int gather_things_leave_cubicle(); // wallet, phone, keys
int look_around(); // what was that sound
int return_for_thermos(); // forgot thermos
int approach_ben(); // hey man, what are you doing here
int call_to_ben(); // hey, who goes there
int ben_is_fine(); // not scared of lurker
int can_i_help(); // can i help you
int run_from_ben(); // bail
void run_for_stairs(int*); // to the stairs
int charge_brenda(); // fuck you brenda
int roof_access(); // to the roof
int sit_edge(); // sitting on the roof
int sit_and_wait(); // waiting on the roof

// Exposition
void display_intro(); // welcome to the game
void leave_roof(); // let's get off this deathtrap

// Survival
void ditch_thermos_completely(); // nope i'm going home
void ben_is_spooky(); // nope too spooky
void keep_moving(); // yay i survived

int main() {
    int decision;
    display_intro();
    decision = intro_decision();
    if (decision == 1) {
        decision = gather_things_leave_cubicle();
        if (decision == 1) {
            decision = return_for_thermos();
            if (decision == 1) {
                decision = ben_is_fine();
                if (decision == 1) {
                    decision = can_i_help();
                    if (decision == 1) {
                        decision = run_from_ben();
                        if (decision == 1) {
                            wait_for_elevator();
                        }
                        else {
                            run_for_stairs(&decision);
                            if (decision == 1) {
                                decision = charge_brenda();
                                if (decision == 1) {
                                    decision = roof_access();
                                    int i = 0;
                                    if (decision == 1) {
                                        decision = sit_edge();
                                        i++;
                                        while (i < 5 && decision != 2) {
                                            decision = sit_and_wait();
                                            i++;
                                        }
                                        if (decision == 1) {
                                            jump_off_roof();
                                        }
                                        else {
                                            leave_roof();
                                        }
                                    }
                                    else {
                                        keep_moving();
                                    }
                                }
                                else {
                                    keep_moving();
                                }
                            }
                            else {
                                jump_cubicle();
                            }
                        }
                    }
                    else {
                        ben_to_hospital();
                    }
                }
                else {
                    reach_past_ben();
                }
            }
            else {
                ben_is_spooky();
            }
        }
        else {
            ditch_thermos_completely();
        }
    }
    else {
        decision = look_around();
        if (decision == 1 ) {
            decision = approach_ben();
            if (decision == 1) {
                decision = run_from_ben();
                if (decision == 1) {
                    wait_for_elevator();
                }
                else {
                    run_for_stairs(&decision);
                    if (decision == 1) {
                        decision = charge_brenda();
                        if (decision == 1) {
                            decision = roof_access();
                            int i = 0;
                            if (decision == 1) {
                                decision = sit_edge();
                                i++;
                                while (i < 5 && decision != 2) {
                                    decision = sit_and_wait();
                                    i++;
                                }
                                if (decision == 1) {
                                    jump_off_roof();
                                }
                                else {
                                    leave_roof();
                                }
                            }
                            else {
                                keep_moving();
                            }
                        }
                        else {
                            keep_moving();
                        }
                    }
                    else {
                        jump_cubicle();
                    }
                }
            }
            else {
                ben_to_hospital();
            }
        }
        else {
            decision = call_to_ben();
            if (decision == 1) {
                decision = run_from_ben();
                if (decision == 1) {
                    wait_for_elevator();
                }
                else {
                    run_for_stairs(&decision);
                    if (decision == 1) {
                        decision = charge_brenda();
                        if (decision == 1) {
                            decision = roof_access();
                            int i = 0;
                            if (decision == 1) {
                                decision = sit_edge();
                                i++;
                                while (i < 5 && decision != 2) {
                                    decision = sit_and_wait();
                                    i++;
                                }
                                if (decision == 1) {
                                    jump_off_roof();
                                }
                                else {
                                    leave_roof();
                                }
                            }
                            else {
                                keep_moving();
                            }
                        }
                        else {
                            keep_moving();
                        }
                    }
                    else {
                        jump_cubicle();
                    }
                }
            }
            else {
                ben_to_hospital();
            }
        }
    }
    return 0;
}

void display_intro() {
    printf("The last few weeks have been normal enough.\n");
    printf("There have been news articles about a mysterious illness lately, but nothing out of the");
    printf(" ordinary.\n");
    printf("It's all just a distraction anyways.\n");
    printf("You know better than to fall for all the garbage.\n");
    printf("Speaking of the man, this job sucks and you know it.\n");
    printf("You've been falling asleep after lunch every day this week and nobody has said a word");
    printf(" yet... Today is Thursday.\n");
    printf("You know you'll probably be fired soon, but who cares?");
    printf("Your story begins here. Time to wake up...\n\n");
    printf("You wake up to the sound of clattering somewhere nearby.\n");
    printf("Shaking off the stiffness that comes with sleeping with your head on the hard wooden");
    printf(" desk in your cubicle, you notice that the office is pitch dark, your cubicle an island");
    printf(" of illumination due to your small desk lamp.\n\n");
    return;
}

int intro_decision() {
    int d;
    printf("Standing up and stretching, you decide to...\n");
    printf("1. Gather your things and head towards the parking garage.\n");
    printf("2. Have a look around.\n\n");
    scanf("%d", &d);
    return d;
}

void reach_past_ben() {
    printf("Nod at Ben and bail with your thermos. ben grabs your arm in a flash and takes massive bite after bite. you scream in horror as you pull back a bloody stump and fall to the floor. you never heard ben's undead moans over your own screaming as he fell upon you.");
}

void ben_to_hospital() {
    printf("Holy shit Ben - your face! We've got to get you to a hospital! Ben's deformed face stretches wide as he opens his mouth like a snake before embracing you and tearing open your jugular");
}

void jump_cubicle() {
    printf("The cubicle wall collapses under your weight and you fall face first on to a desk. nose bleeding and head ringing, you stumble out of the cubicle into ben's arms, who greets you by ripping out your throat");
}
void jump_off_roof() {
    printf("You walk over to the edge of the roof and step off. You relish the cool breeze for the final time.");
}

void leave_roof() {
    printf("Keep moving. I've got to get to my car.");
}

void ditch_thermos_completely() {
    printf("You go to the elevator and ride it down to the parking garage and escape. You win!");
}
void ben_is_spooky() {
    printf("You nope the fuck out of there and get on the elevator, riding down to the parking garage and escape. You win!");
}
void keep_moving() {
    printf("You head down the stairs to the parking garage and escape. You win!");
}

int gather_things_leave_cubicle() {
    int d;
    printf("You get halfway down the hall and realize you forgot your favorite thermos.\n");
    printf("1. Go back and get it\n");
    printf("2. Fuck it. I'll pack it up in my box of shit when they fire me.\n\n");
    scanf("%d", &d);
    return d;
}
int look_around() {
    int d;
    printf("You flick off the lamp light and peer into the darkness of the office, searching for signs of life. After letting your eyes adjust, you notice a figure slowly approaching your cubicle with an odd gait.\n");
    printf("1. Approach the figure\n");
    printf("2. Call out to them\n\n");
    scanf("%d", &d);
    return d;
}
int return_for_thermos() {
    int d;
    printf("Ben the janitor is snooping round your desk\n");
    printf("1. I really want the thermos\n");
    printf("2. Dodge Ben, the renderer of souls\n\n");
    scanf("%d", &d);
    return d;
}
int approach_ben() {
    int d;
    printf("You walk out of your cubicle and ask the figure what they're doing here so late with the lights off; however, a few feet from the individual, you stop dead in your tracks. Ben, the custodian, flinches at the sound of your voice and turns to face you, revealing a grotesque mask of flesh. The left side of his face has been all but removed.\n");
    printf("1. Fucking. Bail.\n");
    printf("2. Holy shit Ben - your face! We've got to get you to a hospital!\n\n");
    scanf("%d", &d);
    return d;
}
int call_to_ben() {
    int d;
    printf("You call out to ben, asking him what he is doing here so late. As he steps closer to the sound of your voice, you realize that this is a zombie.\n");
    printf("1. Fucking. Bail.\n");
    printf("2. Holy shit Ben - your face! We've got to get you to a hospital!\n\n");
    scanf("%d", &d);
    return d;
}
int ben_is_fine() {
    int d;
    printf("Ben, the janitor, is oddly just hovering over your desk\n");
    printf("1. Hey man, can I help you with something?\n");
    printf("2. Nod at Ben and bail with your thermos\n\n");
    scanf("%d", &d);
    return d;
}
int can_i_help() {
    int d;
    printf("Ben flinches at the sound of your voice and turns to face you, revealing a grotesque mask of flesh. The left side of his face has been all but removed.\n");
    printf("1. Fucking. Bail.\n");
    printf("2. Holy shit Ben - your face! We've got to get you to a hospital!\n\n");
    scanf("%d", &d);
    return d;
}
int run_from_ben() {
    int d;
    printf("You bail. turning around, you sprint to the lobby faster than you ever thought you could. you hear squelching of wet flesh dropping to the floor behind you as Ben - or... what's left of him - shambles down the hall after you. You run past the receptionist's desk on your left and mash the elevator button furiously. In a panic, you remember there being a stairwell if you keep going past the receptionist's desk.\n");
    printf("1. Wait for the elevator\n");
    printf("2. Try to find the stairs\n\n");
    scanf("%d", &d);
    return d;
}
void wait_for_elevator() {
    printf("You hear the familiar ding of the elevator's arrival as you see ben turn the corner of the lobby. The look in his remaining eye betray a supernatural hunger that turns your blood to ice. You jump in the elevator and hit the door close button hard enough that it cracks in your hand. You've never seen elevator doors take so long to close. You stand back as ben approaches...gaping his vicious maw and barking with a madman's ferocity. Just as the doors are about to close, the automatic sensors detect Ben and reopen again. You can almost see the grin where ben's face used to be as he sinks his mangled teeth into your throat.");
}

void run_for_stairs(int* dec) {
    printf("the elevator is taking way too fucking long. you make a dash for the stairs on the other side of the office just as ben turns the corner of the lobby. The look in his remaining eye betray a supernatural hunger that turns your blood to ice. you push through the crippling panic and dash through the cubicles on this side of the office - what you find brings a tear to your eye. turning the last corner before you reach the stairwell is another walking corpse - brenda, the receptionist in her business jacket and skirt ensemble - now red\n");
    printf("1. Push past Brenda\n");
    printf("2. Jump over a nearby cubicle wall\n\n");
    scanf("%d", dec);
    return;
}
int charge_brenda() {
    int d;
    printf("Channeling all the time you spend watching mma, you outmaneuver and charge past Brenda to the stairwell entrance. You close the stairwell door on Ben and Brenda and lock it just as they shove their gruesome faces up against the steel mesh reinforced window. you remember the floor above you is roof access, and you're on the 5th floor. The parking garage is B1\n");
    printf("1. Go to the roof\n");
    printf("2. Go to the parking garage\n\n");
    scanf("%d", &d);
    return d;
}
int roof_access() {
    int d;
    printf("A short climb later, you open the roof access door and greet the cool night air. The moment can't be savored for long. You see fires in the distance, parked police lights and with no police nearby, paper and trash strewn about the streets below, and hear the occasional blood-curdling scream as someone else falls victim to this nightmare\n");
    printf("1. Sit and wait... maybe jump\n");
    printf("2. Keep moving. I've got to get to my car.\n\n");
    scanf("%d", &d);
    return d;
}
int sit_edge() {
    int d;
    printf("The sounds of the apocalypse are oddly calming this time of year. At least you don't have to quit your job anymore. There isn't much left for you anymore though...\n");
    printf("1. Sit and wait... maybe jump\n");
    printf("2. Keep moving. I've got to get to my car.\n\n");
    scanf("%d", &d);
    return d;
}
int sit_and_wait() {
    int d;
    printf("The sounds of the apocalypse are oddly calming this time of year. At least you don't have to quit your job anymore. There isn't much left for you anymore though...\n");
    printf("1. Sit and wait... maybe jump\n\n");
    printf("2. Stand up\n");
    scanf("%d", &d);
    return d;
}
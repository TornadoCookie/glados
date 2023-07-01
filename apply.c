#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "glados.h"

void require_continue() {
    char entry[STRING_BUFFER_SIZE];
    printf(">");
    fgets(entry, sizeof(entry), stdin);
    if (streq(entry, "QUIT")) {
        exit(0);
    }
    if (!streq(entry, "CONTINUE")) require_continue();
}

void do_question(int pageN, char *question, bool requires_int, int n_questions) {
    char entry[STRING_BUFFER_SIZE];
    int entry_n;
    clear();
    printf("Form FORMS-EN-2873-FORM - Page %d\n\n\n", pageN);
    printf("%s", question);
    printf(">");
    if (requires_int) {
        scanf("%d", &entry_n);
        if (entry_n > n_questions || entry_n < 1) do_question(pageN, question, requires_int, n_questions);
    } else {
        fgets(entry, sizeof(entry), stdin);
    }
}

int uin;

int main() {
    srand(time(NULL));
    clear();
    printf("Loaded: ENRICHMENT CENTER TEST SUBJECT APPLICATION PROCESS\n");
    printf("FORM  : FORMS-EN-2873-FORM (PART1: PERSONALITY & GENERAL KNOWLEDGE)\n\n\n");
    printf("If you are a first time applicant, please type \"CONTINUE.\"\n\n\n");
    printf("DISREGARD THIS INSTRUCTION if you are returning to form FORMS-EN-2873-FORM after a\n");
    printf("break of any duration for any reason. In that case, you MUST contact your supervisor\n");
    printf("before proceeding. Your supervisor will solicit your Authorized Administrative Unit for\n");
    printf("an affirmative injunction to type \"CONTINUE\".\n\n\n");
    printf("If permission to type \"CONTINUE\" has been granted, please do so now, unless the box\n");
    printf("labeled \"DO NOT TYPE CONTINUE\" on the \"Forms Re-Sanction\" form you should have recieved\n");
    printf("from your supervisor is checked, in which case you should remain at your workstation\n");
    printf("not typing \"CONTINUE\" until such a time as you are instructed by your supervisor to\n");
    printf("discontinue not typing it.\n\n\n");
    require_continue();
    clear();
    printf("Below is your FORMS-EN-2873-FORM Unique Identity Number (Plus Letters) (UIN(+L)):\n\n\n");
    uin = rand();
    printf("[%10d]\n\n\n", uin);
    printf("Please memorize your UIN (+L), as you may be required to recite it from memory as proof. The opening and closing\n");
    printf("braces are decorative and should not be memorized.\n\n\n");
    printf("When you are finished memorizing your case sensitive UIN (+L), type \"CONTINUE\" to proceed.\n\n\n");
    require_continue();

    do_question(1, "If given a choice, what would you like to be called?\n\n\n", false, 0);
    do_question(2, "It is important to consult a physician before starting an Aperture Science Enrichment Center program. If one or\n"
                   "more of the statements listed below applies to you, please contact your supervisor to secure permission to consult\n"
                   "a physician before beginning an Enrichment Center program. Pick the condition that most applies to you.\n\n\n"
                   "1] dizziness\n"
                   "2] shortness of breath\n"
                   "3] problems waking up in the morning\n"
                   "4] problems staying up 48 hours straight\n"
                   "5] have nor previously performed an enrichment center program\n\n\n", true, 5);
    do_question(3, "Sally, Dwayne, Anthony, David, and Franklin are, collectively, exactly 10 years apart in age. Sally's two years older\n"
                   "than David. David's favorite letter is 'g'. Anthony's favorite letter is also 'g', but Dwayne has no preference, insisting\n"
                   "that he likes all the letters equally except for 's'. What is Franklin's favorite letter?\n\n\n"
                   "01] a           19] t\n"
                   "02] b           20] u\n"
                   "03] c           21] v\n"
                   "04] d           22] w\n"
                   "05] e           23] x\n"
                   "06] f           24] y\n"
                   "07] g           25] z\n"
                   "08] h\n"
                   "09] i\n"
                   "10] j\n"
                   "11] k\n"
                   "12] l\n"
                   "13] m\n"
                   "14] n\n"
                   "15] o\n"
                   "16] p\n"
                   "17] q\n"
                   "18] r\n\n\n", true, 25);
    do_question(4, "Which of the following best describes your pain?\n\n\n"
                   "1] Nondescript\n"
                   "2] Shooting\n"
                   "3] Stabbing\n"
                   "4] Burning\n"
                   "5] Prickly\n"
                   "6] Aching\n"
                   "7] Sharp\n"
                   "8] Dull\n\n\n", true, 8);
    do_question(5, "What is your favorite color?\n\n\n"
                   "01] Peach-orange         21] Carmine              41] Brown                 61] Orange               \n"
                   "02] Powder blue          22] Amber                42] Pear                  62] Safety Orange        \n"
                   "03] Cyan                 23] Indigo               43] Orangatang Red        63] Coral                \n"
                   "04] Chartreuse           24] Pale red-violet      44] Chestnut              64] Scarlet              \n"
                   "05] Jade                 25] Lemon Cream          45] Cerulean              65] Light brown          \n"
                   "06] Dark coral           26] Pale chestnut        46] Dark Tea Green        66] Olive Drab           \n"
                   "07] Navy blue            27] Bondi Blue           47] Dark salmon           67] Magenta              \n"
                   "08] Pale mauve           28] Gamboge              48] Sandy brown           68] Bistre               \n"
                   "09] Linen                29] Gold                 49] Dark tan              69] Cerulean blue        \n"
                   "10] Dark goldenrod       30] Steel blue           50] Pine Green            70] Dodger blue          \n"
                   "11] Pumpkin              31] Tangerine            51] Flax                  71] Cobalt               \n"
                   "12] Dark cerulean        32] Lime                 52] Ochre                 72] Violet-eggplant      \n"
                   "13] Zinnwaldite          33] Seashell             53] Bronze                73] Amethyst             \n"
                   "14] Rust                 34] Pale pink            54] Klein Blue            74] Sapphire             \n"
                   "15] Lavender Blush       35] Dark turquoise       55] Pale Sandy Brown      75] Ultramarine          \n"
                   "16] Green                36] Pale cornflower blue 56] Teal                  76] Fuchsia              \n"
                   "17] Lilac                37] Denim                57] Azure                 77] Heliotrope           \n"
                   "18] Blue                 38] Emerald              58] Dark Terra cotta      78] Cinnamon             \n"
                   "19] Midnight Blue        39] Burnt Sienna         59] International orange  79] Chocolate            \n"
                   "20] Tan                  40] Buff                 60] Red                   80] Goldenrod            \n\n\n", true, 80);
    do_question(6, "How do others describe your education?\n\n\n"
                   "01] Nursery School\n"
                   "02] Grade School\n"
                   "03] Junior High\n"
                   "04] High School\n"
                   "05] Some College\n"
                   "06] Associates Degree\n"
                   "07] Bachelors\n"
                   "08] Graduate Degree\n"
                   "09] PhD / Post Doctoral\n"
                   "10] None\n\n\n", true, 10);
    do_question(7, "What is your current living situation?\n\n\n"
                   "01] Live Alone\n"
                   "02] Live With Roomate (s)\n"
                   "03] Live With Kids\n"
                   "04] Live With Parents\n\n\n", true, 4);
    do_question(8, "Do you require any jewelry for health reasons?\n\n\n"
                   "1] Yes\n"
                   "2] No\n\n\n", true, 2);
    do_question(9, "Do you require socks to be a part of your uniform?\n\n\n"
                   "1] Yes\n"
                   "2] No\n\n\n", true, 2);
    do_question(10, "Do you prefer long or short sleeves?\n\n\n"
                    "1] Long Sleeves\n"
                    "2] Short Sleeves\n"
                    "3] Sleeveless / Shirtless / No Preference\n\n\n", true, 3);
    do_question(11, "Does your illness prevent you from working?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(12, "Not including periods of mandatory silence, what is the longest you have gone voluntarily without talking?\n\n\n"
                    "1] 1 Day\n"
                    "2] 2-5 Days\n"
                    "3] 7-14 Days\n"
                    "4] 14-30 Days\n"
                    "5] 30-90 Days\n"
                    "6] 90 Days - 6 Months\n"
                    "7] 1 Year\n"
                    "8] Greater Than 1 Year\n\n\n", true, 8);
    do_question(13, "Do you require music to perform simple tasks?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(14, "Your favorite color is:\n\n\n"
                   "01] Camouflage green     21] Dark pastel green    41] Terra cotta           61] Bright violet        \n"
                   "02] Sangria              22] Dark brown           42] Blaze Orange          62] Corn                 \n"
                   "03] Salmon               23] Papaya whip          43] Dark IndigoRed        63] Eggplant             \n"
                   "04] Pale magenta         24] Dark spring green    44] Violet                64] Bright turquoise     \n"
                   "05] Swamp green          25] Cooked umber         45] Dark tangerine        65] Gray-asparagus       \n"
                   "06] Pastel green         26] Dark chestnut        46] Saffron               66] Moss green           \n"
                   "07] Carrot               27] Dark Khaki           47] Olive                 67] Taupe                \n"
                   "08] Burgundy             28] Russet               48] Tenn                  68] Dark Olive           \n"
                   "09] Mint Green           29] Burnt umber          49] Peache                69] Red-violet           \n"
                   "10] Wheat                30] Wisteria             50] Maroon                70] Burnt Orange         \n"
                   "11] Aqua                 31] Beige                51] Silver                71] Orchid               \n"
                   "12] Thistle              32] Selective yellow     52] Robin egg blue        72] Peach-yellow         \n"
                   "13] Vermillion           33] Viridian             53] Pink                  73] Spring Green         \n"
                   "14] School bus yellow    34] Old Gold             54] Asparagus             74] Lemon                \n"
                   "15] Khaki                35] Mauve                55] Purple                75] Puce                 \n"
                   "16] Cornflower blue      36] Dark violet          56] Pale Blue             76] Periwinkle           \n"
                   "17] Dark light blue      37] Dark pink            57] Dark green            77] Celadon              \n"
                   "18] Dark slate gray      38] Aquamarine           58] Yankee Yellow         78] Dark Scarlet         \n"
                   "19] Mustard              39] Slate gray           59] Navajo white          79] Yellow               \n"
                   "20] Hot pink             40] Royal Blue           60] Fern green            80] Black                \n\n\n", true, 80);
    do_question(15, "Lying about my favorite color makes me feel:\n\n\n"
                    "1] Sorry\n"
                    "2] Not Sorry\n\n\n", true, 2);
    do_question(16, "Are you plagued by suspicions that other people, including coworkers and relatives, may be doing things behind\n"
                    "your back that will hurt you?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(17, "What is your favorite meal?\n\n\n"
                    "1] Lunch\n"
                    "2] Dinner\n\n\n", true, 2);
    do_question(18, "Which pre-Christian mathematician is not correctly matched to his home city?\n\n\n"
                    "01] Thales of Miletus        21] Xenocrates of Chalcedon  \n"
                    "02] Anaximander of Miletus   22] Heraclides of Pontus     \n"
                    "03] Pythagoras of Samos      23] Bryson of Heraclea       \n"
                    "04] Anaximenes of Miletus    24] Theudius of Magnesia     \n"
                    "05] Cleostratus of Tenedos   25] Eudemus of Rhodes        \n"
                    "06] Anaxagoras of Clazomenae 26] Autolycus of Pitane      \n"
                    "07] Zeno of Elea             27] Aristarchus of Samos     \n"
                    "08] Antiphon of Rhamnos      28] Archimedes of Syracuse   \n"
                    "09] Oenopides of Chios       29] Philo of Byzantium       \n"
                    "10] Hippocrates of Chios     30] Nicoteles of Cyrene      \n"
                    "11] Hippias of Elis          31] Eratosthenes of Cyrene   \n"
                    "12] Theodorus of Cyrene      32] Conon of Samos           \n"
                    "13] Philolaus of Croton      33] Apollonius of Perga      \n"
                    "14] Democritus of Abdera     34] Dositheus of Alexandria  \n"
                    "15] Hippasus of Metapontum   35] Dionysodorus of Amisus   \n"
                    "16] Archytas of Tarentum     36] Diocles of Carystus      \n"
                    "17] Theaetetus of Athens     37] Hypsicles of Alexandria  \n"
                    "18] Leodamas of Thasos       38] Hipparchus of Nicaea     \n"
                    "19] Eudoxus of Cnidos        39] Zeno of Sidon            \n"
                    "20] Callipus of Cyzicus      40] Geminus of Rhodes        \n\n\n", true, 40);
    do_question(19, "Please choose the description that best describes your personality:\n\n\n"
                    "01] Childish\n"
                    "02] Oafish\n"
                    "03] Stolid\n"
                    "04] Timid\n"
                    "05] Reserved\n"
                    "06] Conceited\n"
                    "07] Scornful\n"
                    "08] Boastful\n"
                    "09] Sleepy\n"
                    "10] Stable\n\n\n", true, 10);
    do_question(20, "A cake can be sliced into more than seven pieces by making only four diameter cuts through its center.\n\n\n"
                    "1] True\n"
                    "2] False\n\n\n", true, 2);
    do_question(21, "Other than a large egret, what wild animal would you like  to domesticate? NOTE: Several choices, including, but not\n"
                    "limited to, 'Large Egret', may trigger an investigation. Your supervisor has no further information about instigating\n"
                    "animals or the investigatory process, though, upon request, your supervisor can provide further details about this or\n"
                    "her authorized prophylactic unfamiliarity with procedure.\n\n\n[NO DATA, DO THIS LATER!]\n\n\n", false, 0);
    do_question(22,"Which interrogation technique do you think would be most effective on you?\n\n\n"
                   "01] Going Next Door              21] The Spinoza                  41] The Little Bird               \n"
                   "02] Pain                         22] Gospel Shark                 42] Welcome to Bethany            \n"
                   "03] Nobody Loves You             23] Cloud Cuckoo Land            43] Ampere's Rule                 \n"
                   "04] The All-Seeing Eye           24] The Wolf in Sheep's Clothing 44] The Dental Assistant          \n"
                   "05] The Barbering Curriculum     25] Good Cop / Ventriloquist Cop \n"
                   "06] The Informer                 26] Alice in Wonderland          \n"
                   "07] News from Home               27] Monster Polygraph            \n"
                   "08] The Witness                  28] Confession is Good for the Soul\n"
                   "09] Joint Suspects               29] Silver Tongued Devil         \n"
                   "10] The Big Bang                 30] Deep Sea Diver               \n"
                   "11] Pearls Before Swine          31] Pay The Piper                \n"
                   "12] Chicken Button               32] Federal Bikini Inspector     \n"
                   "13] Death Eats a Sandwich        33] Big Wig                      \n"
                   "14] Hammerhead                   34] Carlsbad Caverns             \n"
                   "15] Hammerhand                   35] The Boy Who Cried            \n"
                   "16] Fried Hole                   36] Goonland                     \n"
                   "17] Hangri-La                    37] Role-Role Theory             \n"
                   "18] Ivan Is a Dope               38] Zipf's Law                   \n"
                   "19] Joint Interrogators          39] Stream of Unconsciousness    \n"
                   "20] Law of Partial Pressure      40] Flash in the Pan             \n\n\n", true, 44);
    do_question(23, "Have you experienced recurrent thoughts of regicide?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(24, "If you answered 'yes' to the previous question, please rate the following statement: I know what 'regicide' means.\n\n\n"
                    "1] Strongly Disagree\n"
                    "2] Disagree\n"
                    "3] Agree\n"
                    "4] Strongly Agree\n"
                    "5] N/A\n\n\n", true, 5);
    do_question(25, "You are a liar:\n\n\n"
                    "1] Can't Honestly Disagree\n"
                    "2] Agree\n"
                    "3] Strongly Agree\n\n\n", true, 3);
    do_question(26, "Can you flash your ROM?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(27, "Please acknowledge before continuing:\n\n\n"
                    "I understand that my responses to all items in this questionnaire are the property of Aperture Science. As such,\n"
                    "they will remain strictly confidential, though they may be used to distribute prizes and/or initiate, prolong, or\n"
                    "modify the invasive properties of authorized questioning, investigation, testing, and surveillance.\n\n\n"
                    "1] I have read all or most of the above.\n\n\n", true, 1);
    do_question(28, "Are you functionally incapacitated by witnessing other people's misery?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(29, "Do you get pelasure from solitary pursuits?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(30, "What is your favorite flatware for, purely as an example, eating cake?\n\n\n"
                    "01] Spoon\n"
                    "02] Fork\n"
                    "03] Salad Fork\n"
                    "04] Meat Fork\n"
                    "05] Cocktail Fork\n"
                    "06] Dessert Fork\n"
                    "07] Banquet Fork\n"
                    "08] Serving Fork\n"
                    "09] Fish Fork\n"
                    "10] Table Fork\n"
                    "11] Pastry Fork\n"
                    "12] Knife\n\n\n", true, 12);
    do_question(31, "What is your favorite number between 31 and 37?\n\n\n"
                    "1] 31\n"
                    "2] 32\n"
                    "3] 33\n"
                    "4] 34\n"
                    "5] 35\n"
                    "6] 36\n"
                    "7] 37\n\n\n", true, 7);
    do_question(32, "Do you trust yourself?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(33, "In case you forget your UIN (+L) and need to retrieve it later, please list a crime that only you would know that you\n"
                    "have commmitted:\n\n\n", false, 0);
    do_question(34, "How often do you exercise?\n\n\n"
                    "01] Every Day\n"
                    "02] Every Other Day\n"
                    "03] Twice Weekly\n"
                    "04] Weekly\n"
                    "05] Twice a Month\n"
                    "06] Monthly\n"
                    "07] Yearly\n"
                    "08] Every Few Years\n"
                    "09] Once a Decade\n"
                    "10] Once\n\n\n", true, 10);
    do_question(35, "If you disappeared tomorrow would anyone miss you?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(36, "Would you like to use a prism to study light?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(37, "Do you feel depressed, guilty, or remorseful?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(38, "Do you ever have feelings that people are talking about you or watching you?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(39, "Rate the pain you have been able to withstand without losing consciousness:\n\n\n"
                    "01] 1 - Slight Pain\n"
                    "02] 2\n"
                    "03] 3\n"
                    "04] 4\n"
                    "05] 5 - Regular Pain\n"
                    "06] 6\n"
                    "07] 7\n"
                    "08] 8\n"
                    "09] 9\n"
                    "10] 10 - Worst Pain Imaginable\n\n\n", true, 10);
    do_question(40, "Complete the following statement with the answer that DOES NOT apply to you:\n"
                    "I am often:\n\n\n"
                    "01] worried that life is vague and unreal\n"
                    "02] suspicious of the actions of others\n"
                    "03] prejudiced in favor of my own department, lab, product, skin color, etc.\n"
                    "04] convinced that nobody really cares about me\n"
                    "05] disturbed by the noise of the wind\n"
                    "06] enraged by the petty foibles of those around me\n"
                    "07] irritated by my past faliures and children\n"
                    "08] too depressed to kill an animal or colleague in order to put it out of its pain\n"
                    "09] convinced of the correctness of my opinions on subjects about which I am not an expert\n"
                    "10] speaking very slowly for no apparent reason\n\n\n", true, 10);
    do_question(41, "On a scale of 12 to 11, with the 12 possible choices arranged as on the face of a clock, how would you rate your\n"
                    "awareness of any habitual physical mannerisms such as tugging your ear or hair, eye twitches, hand spasms, etc.?\n\n\n"
                    "01] 12\n"
                    "02] 1\n"
                    "03] 2\n"
                    "04] 3\n"
                    "05] 4\n"
                    "06] 5\n"
                    "07] 6\n"
                    "08] 7\n"
                    "09] 8\n"
                    "10] 9\n"
                    "11] 10\n"
                    "12] 11\n\n\n", true, 12);
    do_question(42, "First Pet's Name:\n\n\n", false, 0);
    do_question(43, "Do you regularly experience deja vu?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(44, "Complete this sentence,\n\n\n", false, 0);
    do_question(45, "Do you feel bad that you have let your coworkers and/or larger mandated collective down?\n\n\n"
                    "1] Yes\n"
                    "2] No\n\n\n", true, 2);
    do_question(46, "Pick the sentence that incorrectly employs the word 'excruciating'.\n\n\n"
                    "1] The test caused excruciating pain.\n"
                    "2] The participant felt excruciating pain.\n"
                    "3] I like to eat cake while excruciating.\n\n\n", true, 3);
    do_question(47, "Choose the correct inspiration for this inspiration phrase, \"You can succeed best and quickest by going it alone.\"\n\n\n"
                    "1] Purpose\n"
                    "2] Patience\n"
                    "3] Success\n"
                    "4] Endurance\n"
                    "5] Courage\n"
                    "6] Teamwork\n\n\n", true, 6);
    do_question(48, "I express my opinions, even if others in the group disagree with me:\"\n\n\n"
                    "1] Almost never\n"
                    "2] Rarely\n"
                    "3] Sometimes\n"
                    "4] Quite often\n"
                    "5] Most of the time\n\n\n", true, 5);
    do_question(49, "Pick your favorite type of cake.\n\n\n"
                   "01] Angel food cake      21] Eccles cake          41] Pineapple Upside Down Cake \n"
                   "02] Apple cake           22] Fairy cake           42] Pound cake            \n"
                   "03] Babka                23] Fifteens             43] Queen Elizabeth cake  \n"
                   "04] Battenburg cake      24] Fruit cake           44] Red bean cake         \n"
                   "05] Baumkuchenn          25] Sponge cake          45] Red velvet cake       \n"
                   "06] Birthday cake        26] Gnoise cake          46] Rhubarb cake          \n"
                   "07] Black forest cake    27] Gingerbread          47] Sachertorte           \n"
                   "08] Buccellato           28] Gob                  48] St. Honore Cake       \n"
                   "09] Bundt cake           29] Gooey butter cake    49] Simnel cake           \n"
                   "10] Butter cake          30] Honey cake           50] Spice cake            \n"
                   "11] Butterfly cake       31] Hot milk cake        51] German chocolate cake \n"
                   "12] Carrot cake          32] Hummingbird cake     52] Stack cake            \n"
                   "13] Cheesecake           33] Ice cream cake       53] Leavened cake, Hefekuchen\n"
                   "14] Chocolate cake       34] Jaffa Cakes          54] Tarte Tatin           \n"
                   "15] Christmas cake       35] Suncake              55] Teacake               \n"
                   "16] Chiffon cake         36] Mooncake             56] Tres leches cake      \n"
                   "17] Croquembouche        37] Orehnjac(a           57] Vanilla slice         \n"
                   "18] Cupcake              38] Pancake              58] Vanilla Crazy Cake    \n"
                   "19] Date and walnut loaf 39] Panettone            59] Victoria Sponge       \n"
                   "20] Devil's food cake    40] Petit fours          60] Wedding cake          \n\n\n", true, 60);
    do_question(50, "Gender\n\n\n", false, 0);
    clear();
    printf("Congratulations!\n\n\n");
    printf("You have finished the:\n\n\n");
    printf("ENRICHMENT CENTER TEST SUBJECT APPLICATION\n");
    printf("FORMS-EN-2873-FORM (PART1: PERSONALITY & GENERAL KNOWLEDGE)\n\n\n");
    printf("Please enter your 10 digit UIN (+L) to complete the process.\n\n\n");
    int try_uin;
    printf(">");
    scanf("%10d", &try_uin);
    if (try_uin == uin) {
        clear();
        printf("Have a very safe day..........\n");
        #ifdef _WIN32
        system("ping 127.0.0.1 -n 2 > NUL");
        #else
        system("sleep 1");
        #endif
        return 0;
    }
    clear();
    printf("The entered UIN (+L) does not match your assigned UIN (+L).\n\n\n");
    printf("Please REMAIN AT YOUR WORKSTATION until a Computer-Aided-Enrichment Crisis Team arrives.\n\n\n");
    while (1) {}
    return 0;
}
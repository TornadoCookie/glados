#include <stdio.h>
#include <stdlib.h>

void clear() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}

void more() {
    printf("[MORE]");
    getchar();
    clear();
}

int main() {
    clear();
    printf("1953 - Aperture Science begins operations as a manufacturer of shower curtains. Early product line provides a very\n");
    printf("low-tech portal between the inside and outside of your shower. Very little science is actually involved. The name is\n");
    printf("chosen to make the curtains appear more hygienic.\n\n\n");
    printf("1956-Eisenhower administration awards Aperture a contract to provide shower curtains to all branches of the\n");
    printf("military except the Navy.\n\n\n");
    printf("1957 - 1975 - Mostly shower curtains.\n\n\n");
    printf("1978 - Aperture Founder and CEO, Cave Johnson, is exposed to mercury while secretly developing a dangerous\n");
    printf("mercury-injected rubber sheeting from which he plans to manufacture seven deadly shower curtains to be given as\n");
    printf("gifts to each member of the House Naval Appropriations committee.\n\n\n\n");
    more();
    printf("1979 - Both of Cave Johnson's kidney's fail. Brain damaged, dying, and incapable of being convinced that time is not\n");
    printf("now flowing backwards, Johnson lays out a three tiered R&D program. The results, he says, will 'guarantee the\n");
    printf("continued success of Aperture Science far into the fast-approaching distant past.'\n\n\n");
    printf("Tier 1: The Heimlich Counter-Maneuver - A reliable technique for interrupting the life-saveing Heimlich Maneuver.\n\n\n");
    printf("Tier 2: The Take-A-Wish Foundation - A charitable organization that will purchase wishes from the parents of\n");
    printf("terminally ill children and redistribute them to wish-deprived but otherwise health adults.\n\n\n");
    printf("Tier 3: 'Some kind of rip in the fabric of space... That would... Well, it'd be like, I dont't know, something that would\n");
    printf("help with the shower curtains I guess. I haven't worked this idea out as much as the wish-taking one.'\n\n\n\n");
    more();
    printf("1981 - Diligent Aperture engineers complete the Heimlich Counter-Maneuver and Take-A-Wish Foundation\n");
    printf("initatives. The company announces products related to the research in a lavish, televised ceremony. These\n");
    printf("products become immediately wildly unpopular. After a string of very public choking and despondent sick child\n");
    printf("disasters, senior company officials are summoned before a Senate investigative committe. During these\n");
    printf("proceedings, an engineer mentions that some progress has been made on Tier 3, the 'man-sized ad hock quantum\n");
    printf("tunnel through physical space with possible applications as a shower curtain.' The committe is quickly\n");
    printf("permanently recessed, and Aperture is granted an open-ended contract to secretly continue research on the\n");
    printf("'Portal' amd Heimlich Counter-Maneuver projects.\n\n\n\n");
    more();
    printf("1981 - 1985 - Work progresses on the 'Portal' project. Several high ranking Fatah personnel choke to death on lamb\n");
    printf("chunks despite the intervention of their bodyguards.\n\n\n");
    printf("1986 - Word reaches Aperture management that another defense contracter called Black Mesa is working on a\n");
    printf("similar portal technology. In response to this news, Aperture begins developing the Genetic Lifeform and Disk\n");
    printf("Operating System (GLaDS), an artifically intelligent research assistant and disk operating system.\n\n\n");
    printf("1996 - After a decase spent bringing the disk operating parts of GLaDOS to a state of mroe or less basic\n");
    printf("functionality, work begins on the Genetic Lifeform component.\n\n\n");
    printf("200- - The untested AI is activated for the first time as one of the planned activities on Apertures's first\n");
    printf("annual bring-your-daughter-to-work day.\n\n\n");
    printf("In many ways, the inital test goes well...\n\n\n\n");
    printf("[END]");
    getchar();
    clear();
    return 0;
}
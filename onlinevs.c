
typedef struct {
    char name[30];
    char party[30];
    int votes;
} Candidate;

Voter voters[MAX_VOTERS] = {
    {"V001", "1234", 0},
    {"V002", "5678", 0},
    {"V003", "4321", 0},
    {"V004", "8765", 0},
    {"V005", "1111", 0},
    {"V006", "2222", 0},
    {"V007", "3333", 0},
    {"V008", "4444", 0},
    {"V009", "5555", 0},
    {"V010", "6666", 0}
};

Candidate candidates[MAX_CANDIDATES] = {
    {"Arjun Sharma", "Progressive Alliance", 0},
    {"Priya Mehta", "National Front", 0},
    {"Rahul Verma", "United Peoples Party", 0},
    {"Sunita Rao", "Green Future", 0},
    {"Kiran Patel", "Independent", 0}
};

int totalVotesCast = 0;

void printDivider() {
    printf("==========================================\n");
}

void displayLiveTally() {
    printDivider();
    printf("LIVE VOTE TALLY\n");
    printDivider();

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s (%s) - Votes: %d\n",
               candidates[i].name,
               candidates[i].party,
               candidates[i].votes);
    }
}

int authenticateVoter(char *id, char *pin) {
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (strcmp(voters[i].id, id) == 0 &&
            strcmp(voters[i].pin, pin) == 0) {
            return i;
        }
    }
    return -1;
}

void castVote(int idx) {
    int choice;

    printf("\nCandidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s (%s)\n", i + 1,
               candidates[i].name,
               candidates[i].party);
    }

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_CANDIDATES) {
        printf("Invalid choice!\n");
        return;
    }

    candidates[choice - 1].votes++;
    voters[idx].hasVoted = 1;
    totalVotesCast++;

    printf("Vote cast successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printDivider();
        printf("1. Vote\n2. View Tally\n3. Exit\n");
        printDivider();

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char id[ID_LENGTH], pin[PIN_LENGTH];

            printf("Enter ID: ");
            scanf("%s", id);

            printf("Enter PIN: ");
            scanf("%s", pin);

            int idx = authenticateVoter(id, pin);

            if (idx == -1) {
                printf("Invalid ID or PIN!\n");
            } else if (voters[idx].hasVoted) {
                printf("Already voted!\n");
            } else {
                castVote(idx);
            }

        } else if (choice == 2) {
            displayLiveTally();

        } else if (choice == 3) {
            printf("Exiting...\n");
            break;

        } else {
            printf("Invalid option!\n");
        }
    }

    return 0;
}

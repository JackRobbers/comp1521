struct _enrolment {
    int stu_id;         // e.g. 5012345
    char course[9]:     // e.g. "COMP1521"
    char term[5];       // e.g. "17s2"
    char grade[3];      // e.g. "HD"
    double mark;        // e.g. 87.3
};

// 4 + 9 + 5 + 3 + 8
// 29, actually 32 bytes

struct _enrolment {
    int stu_id;         // e.g. 5012345
    double mark;        // e.g. 87.3
    char course[9]:     // e.g. "COMP1521"
    char term[5];       // e.g. "17s2"
    char grade[3];      // e.g. "HD"
};


struct node {
    int value
    struct node next;
}

// a size of 29
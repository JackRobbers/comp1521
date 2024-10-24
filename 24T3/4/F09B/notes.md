// infinite
struct _node {
    int value;
    Node next;
};

// finite
struct _node {
    int value;
    Node *next;
};

struct _enrolment {
    int stu_id;        // 4 bytes, offset 0
    char course[9]:    // 9 bytes, offset 4
    char term[5];      // 5 bytes, offset 13
    char grade[3];     // 3 bytes, offset 18
    double mark;       // 8 bytes, offset 24
}; size = 32

struct _enrolment {
    double mark;       // 8 bytes, offset 24
    int stu_id;        // 4 bytes, offset 0
    char course[9]:    // 9 bytes, offset 4
    char term[5];      // 5 bytes, offset 13
    char grade[3];     // 3 bytes, offset 18
}; size = 30
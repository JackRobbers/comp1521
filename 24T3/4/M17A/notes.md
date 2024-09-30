struct _enrolment {
    int stu_id;         // 4 bytes, offset 0
    char course[9]:     // 9 bytes, offset 4
    char term[5];       // 5 bytes, offset 13
    char grade[3];      // 3 bytes, offset 18
    double mark;        // 8 byes, offest 24
};

sizeof(_enrolment) == 32

struct _enrolment {
    int stu_id;         // 4 bytes, offset 0
    double mark;        // 8 bytes, offest 4
    char course[9]:     // 9 bytes, offset 12
    char term[5];       // 5 bytes, offset 21
    char grade[3];      // 3 bytes, offset 26
};

sizeof(_enrolemnet) == 29
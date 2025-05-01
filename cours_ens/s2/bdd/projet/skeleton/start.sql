CREATE TABLE 'student' (
    'id'            SERIAL      PRIMARY KEY,
    'last_name'     TEXT        NOT NULL,
    'first_name'    TEXT        NOT NULL,
    'phone_number'  TEXT        NOT NULL, 
    CHECK (length('phone_number') <= 14 AND length('phone_number') >= 6)
);

CREATE TABLE 'accounts' (
    'id'            INTEGER     PRIMARY KEY,
    'balance'       DECIMAL     NOT NULL,
    CHECK ('balance' >= 0 AND 'balance' <= 1000000000),
    FOREIGN KEY ('id') REFERENCES 'student' ('id') ON DELETE CASCADE,
);

CREATE TABLE 'history_transferts' (
    'id'                SERIAL      PRIMARY KEY,
    'src_account_id'    INTEGER     NOT NULL,
    'dest_account_id'   INTEGER     NOT NULL,
    'amount'            DECIMAL     NOT NULL,
    'date'              TIMESTAMP   NOT NULL DEFAULT NOW(),
    CHECK ('amount' >= 0 AND 'amount' <= 1000000000),
    CHECK ('src_account_id' <> 'dest_account_id'),
    FOREIGN KEY ('src_account_id') REFERENCES 'accounts' ('id') ON DELETE CASCADE,
    FOREIGN KEY ('dest_account_id') REFERENCES 'accounts' ('id') ON DELETE CASCADE
);

CREATE TABLE 'history_deposits' (
    'id'                SERIAL      PRIMARY KEY,
    'account_id'        INTEGER     NOT NULL,
    'amount'            DECIMAL     NOT NULL,
    'date'              TIMESTAMP   NOT NULL DEFAULT NOW(),
    FOREIGN KEY ('account_id') REFERENCES 'accounts' ('id') ON DELETE CASCADE
);

CREATE TABLE 'teachers' (
    'id'            SERIAL      PRIMARY KEY,
    'last_name'     TEXT        NOT NULL,
    'first_name'    TEXT        NOT NULL,
    'phone_number'  TEXT        NOT NULL, 
    CHECK (length('phone_number') <= 14 AND length('phone_number') >= 6)
);

CREATE TABLE 'curriculums' (
    'id'            SERIAL      PRIMARY KEY,
    'name'          TEXT        NOT NULL,
    'director_id'   INTEGER     NOT NULL,
    FOREIGN KEY ('director_id') REFERENCES 'teachers' ('id')
);

CREATE TABLE 'courses' (
    'id'            SERIAL      PRIMARY KEY,
    'name'          TEXT        NOT NULL,
    'teacher_id'    INTEGER     NOT NULL,
    FOREIGN KEY ('teacher_id') REFERENCES 'teachers' ('id')
);

CREATE TABLE 'curriculum_courses' (
    'curriculum_id' INTEGER     NOT NULL,
    'course_id'     INTEGER     NOT NULL,
    'ects'          INTEGER     NOT NULL,
    CHECK ('ects' > 0),
    PRIMARY KEY ('curriculum_id', 'course_id'),
    FOREIGN KEY ('curriculum_id') REFERENCES 'curriculums' ('id') ON DELETE CASCADE,
    FOREIGN KEY ('course_id') REFERENCES 'courses' ('id') ON DELETE CASCADE
);

CREATE TABLE 'student_curriculums' (
    'student_id'    INTEGER     NOT NULL,
    'curriculum_id' INTEGER     NOT NULL,
    PRIMARY KEY ('student_id', 'curriculum_id'),
    FOREIGN KEY ('student_id') REFERENCES 'student' ('id') ON DELETE CASCADE,
    FOREIGN KEY ('curriculum_id') REFERENCES 'curriculums' ('id') ON DELETON DELETE CASCADEE CASCADE
);

CREATE TABLE 'validations' (
    'id'            SERIAL      PRIMARY KEY,
    'name'          TEXT        NOT NULL,
    'date'          TIMESTAMP   NOT NULL,
    'coef'          INTEGER     NOT NULL,
    'course_id'     INTEGER     NOT NULL,
    CHECK ('coef' > 0),
    FOREIGN KEY ('course_id') REFERENCES 'courses' ('id') ON DELETE CASCADE
);

CREATE TABLE 'grades' (
    'validation_id' INTEGER     NOT NULL,
    'student_id'    INTEGER     NOT NULL,
    'grade'         DECIMAL     NOT NULL,
    CHECK ('grade' >= 0 AND 'grade' <= 20)
    PRIMARY KEY ('validation_id', 'student_id'),
    FOREIGN KEY ('validation_id') REFERENCES 'validations' ('id') ON DELETE CASCADE,
    FOREIGN KEY ('student_id') REFERENCES 'student' ('id') ON DELETE CASCADE
);

CREATE TABLE 'student_course' (
    'student_id'    INTEGER NOT NULL,
    'course_id'     INTEGER NOT NULL,
    PRIMARY KEY ('student_id', 'course_id'),
    FOREIGN KEY ('course_id') REFERENCES 'course' ('id') ON DELETE CASCADE,
    FOREIGN KEY ('student_id') REFERENCES 'student' ('id') ON DELETE CASCADE
);
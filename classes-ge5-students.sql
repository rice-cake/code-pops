Problem 596 (Easy): 

create table If Not Exists Courses (student varchar(255), class varchar(255));
truncate table Courses;
insert into Courses (student, class) values ('A', 'Math');
insert into Courses (student, class) values ('B', 'English');
insert into Courses (student, class) values ('C', 'Math');
insert into Courses (student, class) values ('D', 'Biology');
insert into Courses (student, class) values ('E', 'Math');
insert into Courses (student, class) values ('F', 'Computer');
insert into Courses (student, class) values ('G', 'Math');
insert into Courses (student, class) values ('H', 'Math');
insert into Courses (student, class) values ('I', 'Math');
insert into Courses (student, class) values ('B', 'English');
insert into Courses (student, class) values ('B', 'English');
insert into Courses (student, class) values ('B', 'English');
insert into Courses (student, class) values ('B', 'English');
insert into Courses (student, class) values ('B', 'English');
insert into Courses (student, class) values ('B', 'English');
insert into Courses (student, class) values ('B', 'English');

There is the table Courses with columns: student and class

Please list out all classes which at least 5 students.

For example, with the table:

+---------+------------+
| student | class      |
+---------+------------+
| A       | Math       |
| B       | English    |
| C       | Math       |
| D       | Biology    |
| E       | Math       |
| F       | Computer   |
| G       | Math       |
| H       | Math       |
| I       | Math       |
+---------+------------+


Should output:

+---------+
| class   |
+---------+
| Math    |
+---------+


Note:
The students should not be counted twice in each course.


-----------------------------

My solution (Accepted):

select class from 
(select distinctrow * from Courses) as C
group by class having count(class) >= 5 ;


-----------------------------
Another (Suggested) solution:

SELECT class
FROM courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5 ;


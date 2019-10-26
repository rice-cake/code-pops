Problem 182 (Easy):

create table If Not Exists Person (Id int, Email varchar(255));
truncate table Person
insert into Person (Id, Email) values ('1', 'a@b.com');
insert into Person (Id, Email) values ('2', 'c@d.com');
insert into Person (Id, Email) values ('3', 'a@b.com');

Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+

Note: All emails are in lowercase.


-----------------------------

My solution (Accepted):

# derived table, group by aggregation, count

select Email from 

(select Email, count(Email) as ects from Person group by Email) as t1

where ects > 1 ; 



-----------------------------

Suggested solution:

select Email
from Person
group by Email
having count(Email) > 1;



Problem 196 (Easy -ish):

Write a SQL query to delete all duplicate email entries in a table named Person, keeping only unique emails based on its smallest Id.

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Id is the primary key column for this table.

For example, after running your query, the above Person table should have the following rows:

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+

Note:

Your output is the whole Person table after executing your sql. Use delete statement.

-----------------------------

My solution (requires mySQL 8):

# selects rows with smallest Id for each distinct Email
# requires Id to be primary key, otherwise use min(Id)

with my_tmp as (select Id from Person group by Email)
delete from Person
where Id not in (select Id from my_tmp) ;

-----------------------------

Posted solution (I found most understandable):

delete from Person
where id not in (select min(p.id) from 
			(select * from Person) as p 
				group by p.Email);




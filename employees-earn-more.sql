Problem 181 (Easy):

create table If Not Exists Employee (Id int, Name varchar(255), Salary int, ManagerId int);
truncate table Employee;
insert into Employee (Id, Name, Salary, ManagerId) values ('1', 'Joe', '70000', '3');
insert into Employee (Id, Name, Salary, ManagerId) values ('2', 'Henry', '80000', '4');
insert into Employee (Id, Name, Salary, ManagerId) values ('3', 'Sam', '60000', Null);
insert into Employee (Id, Name, Salary, ManagerId) values ('4', 'Max', '90000', Null);

The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.

+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+

Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.

+----------+
| Employee |
+----------+
| Joe      |
+----------+

-----------------------------

My solution (Accepted):

# subquery on the same table

select E1.Name as "Employee"
from Employee as E1
where E1.Salary > (select E2.Salary from Employee as E2 
		where E1.ManagerId = E2.Id)

-----------------------------

Other solutions:

select a.Name as 'Employee'
from Employee as a, Employee as b
where a.ManagerId = b.Id AND a.Salary > b.Salary ;


# self-join

select a.NAME as Employee
from Employee as a JOIN Employee as b
on a.ManagerId = b.Id AND a.Salary > b.Salary ;


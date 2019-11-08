Problem 620 (Easy): 

create table If Not Exists Cinema (id int, movie varchar(255), description varchar(255), rating float(2, 1));
truncate table Cinema;
insert into Cinema (id, movie, description, rating) values ('1', 'War', 'great 3D', '8.9');
insert into Cinema (id, movie, description, rating) values ('2', 'Science', 'fiction', '8.5');
insert into Cinema (id, movie, description, rating) values ('3', 'irish', 'boring', '6.2');
insert into Cinema (id, movie, description, rating) values ('4', 'Ice song', 'Fantacy', '8.6');
insert into Cinema (id, movie, description, rating) values ('5', 'House card', 'Interesting', '9.1');
insert into Cinema (id, movie, description, rating) values ('6', 'Matrix', 'BorinG', '3.1');

X city opened a new cinema, many people would like to go to this cinema. 
The cinema also gives out a poster indicating the movies’ ratings and descriptions.

Please write a SQL query to output movies with an odd numbered ID and a description that is not 'boring'. 
Order the result by rating.


For example, table cinema:

+---------+-----------+--------------+-----------+
|   id    | movie     |  description |  rating   |
+---------+-----------+--------------+-----------+
|   1     | War       |   great 3D   |   8.9     |
|   2     | Science   |   fiction    |   8.5     |
|   3     | irish     |   boring     |   6.2     |
|   4     | Ice song  |   Fantacy    |   8.6     |
|   5     | House card|   Interesting|   9.1     |
+---------+-----------+--------------+-----------+

For the example above, the output should be:

+---------+-----------+--------------+-----------+
|   id    | movie     |  description |  rating   |
+---------+-----------+--------------+-----------+
|   5     | House card|   Interesting|   9.1     |
|   1     | War       |   great 3D   |   8.9     |
+---------+-----------+--------------+-----------+


-----------------------------

My solution (Accepted):


select * from Cinema
where lower(description) != 'boring'
and id % 2 = 1
order by rating desc ;


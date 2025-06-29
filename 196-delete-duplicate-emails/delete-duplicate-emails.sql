# Write your MySQL query statement below
DELETE from Person
WHERE id NOT IN(
    SELECT * FROM(
        SELECT min(id) 
        FROM Person
        GROUP BY email
    ) AS temp
);
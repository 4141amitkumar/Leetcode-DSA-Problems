# Write your MySQL query statement below
WITH CTE AS(
    SELECT salary, DENSE_RANK() over (ORDER BY salary DESC) AS rnk
    FROM Employee
)
SELECT 
    (SELECT salary FROM CTE WHERE rnk = 2 LIMIT 1) 
    AS SecondHighestSalary;
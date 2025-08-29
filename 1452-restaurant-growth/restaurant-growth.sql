# Write your MySQL query statement below
WITH cte AS(
    SELECT visited_on, SUM(amount) as amount, ROW_NUMBER() OVER (ORDER BY visited_on) as rnk
    FROM Customer
    GROUP BY visited_on
),
cte2 AS(
    SELECT visited_on, SUM(amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 preceding AND current row) as amount, ROUND(AVG(amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 preceding AND current row),2)  as average_amount,rnk
    FROM cte
)
SELECT visited_on, amount, average_amount
FROM cte2
WHERE rnk>6
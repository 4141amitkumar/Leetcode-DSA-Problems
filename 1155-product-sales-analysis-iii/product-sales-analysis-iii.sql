# Write your MySQL query statement below
WITH rnk AS(
    SELECT *, RANK() OVER (PARTITION BY product_id ORDER BY year) as ranking
    FROM Sales
)
SELECT product_id, year as first_year, quantity, price
FROM rnk
WHERE ranking=1;
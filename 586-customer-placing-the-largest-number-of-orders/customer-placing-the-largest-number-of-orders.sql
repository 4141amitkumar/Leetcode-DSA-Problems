# Write your MySQL query statement below
# FOLLOW UP SOLUTION

WITH OrderCounts AS (
    SELECT customer_number, COUNT(*) AS order_count
    FROM Orders
    GROUP BY customer_number
),
MaxCount AS(
    SELECT MAX(order_count) AS max_orders
    FROM OrderCounts
)

SELECT customer_number
FROM OrderCounts
WHERE order_count = (SELECT max_orders FROM MaxCount);
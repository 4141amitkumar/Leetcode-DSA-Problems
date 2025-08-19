# Write your MySQL query statement below
WITH ranked AS(
    SELECT *, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) as rnk
    FROM Delivery
)
SELECT ROUND(SUM(CASE WHEN rnk=1 AND order_date=customer_pref_delivery_date THEN 1 ELSE 0 END)/COUNT(DISTINCT customer_id)*100,2) AS immediate_percentage
FROM ranked;
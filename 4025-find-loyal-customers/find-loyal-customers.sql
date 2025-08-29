# Write your MySQL query statement below
WITH cte AS(
    SELECT customer_id, COUNT(customer_id) as cnt, SUM(
    CASE WHEN transaction_type='refund' THEN 1 ELSE 0 END
    ) as refund_times, MIN(transaction_date) as first_active, MAX(transaction_date) as last_active
    FROM customer_transactions
    GROUP BY customer_id
)
SELECT customer_id
FROM cte
WHERE cnt>2 AND ROUND((refund_times/cnt),2)<0.20 AND DATEDIFF(last_active, first_active)>=30
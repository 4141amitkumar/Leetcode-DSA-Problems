# Write your MySQL query statement below
SELECT c.category, COUNT(a.income) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
) AS c
LEFT JOIN accounts a ON (
    c.category = CASE
                     WHEN income < 20000 THEN 'Low Salary'
                     WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
                     ELSE 'High Salary'
                END
)
GROUP BY c.category;
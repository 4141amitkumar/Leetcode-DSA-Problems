# Write your MySQL query statement below
WITH stock_price AS (
    SELECT stock_name,
    SUM(CASE WHEN operation='Buy' THEN price ELSE 0 END) AS buy_price,
    SUM(CASE WHEN operation='Sell' THEN price ELSE 0 END) AS sell_price
    FROM Stocks
    GROUP BY stock_name
)

SELECT stock_name, sell_price - buy_price AS capital_gain_loss
FROM stock_price;
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT salary
      FROM (
        SELECT id, salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS Salary_order
        FROM Employee
      ) as sorted
      WHERE Salary_order = N
      LIMIT 1
  );
END
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N-1;
  RETURN (
      # Write your MySQL query statement below.
      Select DISTINCT Employee.salary from Employee order by salary DESC LIMIT M,1
  );
END
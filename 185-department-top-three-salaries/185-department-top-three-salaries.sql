# Write your MySQL query statement below
SELECT d.Name as Department, e.Name as Employee, e.Salary FROM Employee e INNER JOIN Department d
ON e.DepartmentId = d.Id
WHERE (SELECT COUNT(DISTINCT m.Salary) FROM Employee m where m.DepartmentId = e.DepartmentId and m.Salary > e.Salary) < 3;

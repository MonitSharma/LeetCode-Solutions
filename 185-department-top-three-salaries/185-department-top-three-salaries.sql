SELECT d.Name as Department,
e.Name as Employee,
e.Salary as Salary
FROM Department d, Employee e
WHERE(
    SELECT COUNT(distinct Salary)
    FROM Employee
    WHERE Salary > e.Salary AND DepartmentId = d.Id
) < 3 AND e.DepartmentId = d.Id
ORDER BY d.Id, e.Salary desc;
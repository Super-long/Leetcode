select distinct Salary SecondHighestSalary 
from Employee
order by Salary desc
limit 1 offset 1;

SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;

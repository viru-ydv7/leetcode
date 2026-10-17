# Write your MySQL query statement below
select e1.name,e2.bonus from employee e1 left join bonus e2 on e1.empId=e2.empId WHERE e2.bonus <1000 OR e2.bonus is NULL;
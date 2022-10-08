-- CREATE TABLE
CREATE TABLE Students (
    id INT NOT NULL,
    fullname VARCHAR(20) NOT NULL,
    major VARCHAR(10),
    age INT,
);

-- describe table
DESC Students;

-- ALTER TABLE => maniplate structure of table/database
-- add/remove column
ALTER TABLE Students ADD address VARCHAR(30);
ALTER TABLE Students DROP COLUMN address;
-- modify data-type
ALTER TABLE Students MODIFY id VARCHAR(10);
-- add/remove constraints
ALTER TABLE Students ADD CONSTRAINT PK_Student PRIMARY KEY (id);
ALTER TABLE Students ADD UNIQUE (id);
ALTER TABLE Students DROP CONSTRAINT PK_Student;
-- rename column/table
ALTER TABLE Students RENAME COLUMN id TO roll_no;
ALTER TABLE Students RENAME TO Student_Details;

-- UPDATE
UPDATE Students SET major = "CS" WHERE id = 2;

-- DROP TABLE => delete whole table along with its sturcture
DROP TABLE Students;

-- TRUNCATE => delete all rows/tuples in one go (faster | no roll-back)
TRUNCATE Students;

-- DELETE => delete selected rows/tuples from table (slower | roll-back possible)
DELETE FROM Students WHERE id = 3;

-- INSERT
INSERT INTO Student VALUES (101, 'Anand', Mathematics, 20);





-- JOINS (Cross Product + Condition)
-- natural join
-- self join
-- outer join



-- Aggregate Functions

-- select maximum salary
SELECT MAX(salary) FROM Employees;
-- counts rows having non-null and distinct salaries
SELECT DISTINCT COUNT(salary) FROM Employees;
SELECT AVG(salary) FROM Employees;



-- Sub Queries (Nested Queries / Correlated Queries)

-- select employee with highest salary
SELECT fullname, dept FROM Employees WHERE salary = (SELECT MAX(salary) FROM Employees);

-- select 2nd highest salary
SELECT MAX(salary) FROM Employees WHERE salary != (SELECT MAX(salary) FROM Employees);

-- select employee with 2nd highest salary
SELECT fullname, dept FROM Employees WHERE salary = (SELECT MAX(salary) FROM Employees WHERE salary != (SELECT MAX(salary) FROM Employees));


-- select employee with 4th highest salary (Preferred - correlated query)
SELECT * FROM Employees emp1
WHERE 3 = (SELECT COUNT(DISTINCT salary) FROM Employees emp2 WHERE emp2.salary > emp1.salary);


-- select departments along with no. of employees working in that
SELECT dept, COUNT(eid) FROM Employees GROUP BY dept HAVING COUNT(*) < 2;


-- select employee who are working on some projects (Nested query)
SELECT fullname FROM Employees 
WHERE eid IN (SELECT eid FROM Projects);

-- select employee who are working on some projects (Correlated query)
SELECT * FROM Employees 
WHERE EXISTS (SELECT eid FROM Projects WHERE Employees.eid = Projects.eid);

-- select employee who are working on some projects (join)
SELECT fullname FROM Employees, Departments WHERE Employees.did = Departments.did;

-- select employee name with highest salary department wise
SELECT fullname FROM Employees 
WHERE salary IN (SELECT dept, MAX(salary) FROM Employees GROUP BY dept);


-- Nested Query (Bottom-up)
SELECT * FROM Employees 
WHERE eid IN (SELECT eid FROM Departments);

-- Correlated Query (Top-down)
SELECT * FROM Employees 
WHERE EXISTS (SELECT eid FROM Departments WHERE Employees.eid = Departments.eid);



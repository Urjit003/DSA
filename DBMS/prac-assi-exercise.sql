show databases;
use db1;

create table db1.Client_master (
	Client_No varchar(6) ,
    Name varchar(20) NOT NULL,
    Address1 varchar(30) ,
	Address2 varchar(30) ,
    City varchar(15),
    PinCode numeric(8),
    State Varchar(15),
    Bal_due float(10,2),
    primary key (Client_No) ,
    CHECK ((Client_No) LIKE 'C%')
);
	drop table db1.Client_master;
	truncate table db1.Client_master;
    select * from db1.Client_master;
		
	INSERT INTO db1.Client_master (Client_No, Name, City, PinCode, State, Bal_due)
	VALUES
	('C00001', 'Ivan Bayross', 'Bombay', 400054, 'Maharashtra', 15000),
	('C00002', 'Vandana Saitwal', 'Madras', 780001, 'Tamil Nadu', 0),
	('C00003', 'Pramada Jaguste', 'Bombay', 400057, 'Maharashtra', 5000),
	('C00004', 'Basu Navindgi', 'Bombay', 400056, 'Maharashtra', 0),
	('C00005', 'Ravi Sreedharan', 'Delhi', 100001, 'Delhi', 2000),
	('C00006', 'Rukmini', 'Bombay', 400050, 'Maharashtra', 0);


create table db1.product_master (
	Product_no varchar(6),
    Description varchar(15) NOT NULL,
    Profile_percent float(4,2)NOT NULL,
    Unit_measure varchar(10)NOT NULL,
    Qty_on_hand numeric(8) NOT NULL,
    Recorder_lvl numeric(8)NOT NULL,
	Sell_price numeric(8,2)NOT NULL,
    Cost_price numeric(8,2)NOT NULL,
    primary key (Product_no),
    check (Product_no like 'P%'),
    check (Sell_price > 0) ,
    check (Cost_price > 0)
);
	desc db1.product_master;
    select * from db1.product_master;
    INSERT INTO db1.product_master (Product_no, Description, Profile_percent, Unit_measure, Qty_on_hand, Recorder_lvl, Sell_Price, Cost_Price)
	VALUES
	('P00001', '1.44 Floppies', 5.00, 'Piece', 100, 2, 525.00, 500.00),
	('P03453', 'monitors', 6.00, 'Piece', 10, 20, 12000.00, 11280.00),
	('P06734', 'mouse', 5.00, 'Piece', 20, 3, 1050.00, 1000.00),
	('P07865', '1.22 Floppies', 5.00, 'Piece', 100, 5, 525.00, 500.00),
	('P07868', 'keyboards', 2.00, 'Piece', 10, 20, 3150.00, 3050.00),
	('P07885', 'CD Drive', 2.50, 'Piece', 10, 3, 5250.00, 5100.00),
	('P07965', '540 HHD', 4.00, 'Piece', 10, 3, 8400.00, 8000.00),
	('P07975', '1.44 Drive', 5.00, 'Piece', 10, 3, 1050.00, 1000.00),
	('P08865', '1.22 Drive', 5.00, 'Piece', 2, 3, 1050.00, 1000.00);


CREATE TABLE db1.salesman_master (
    salesman_no varchar(6) ,
    Salesman_name varchar(20) NOT NULL,
    Address1 varchar(30) NOT NULL,
    Address2 varchar(30),
    City varchar(20),
    Pincode varchar(8),
    State varchar(20),
    Sal_amt numeric(8, 2) NOT NULL,
    Tgt_to_get numeric(6, 2) NOT NULL,
    Ytd_sales numeric(6, 2) NOT NULL,
    Remarks varchar(60) ,
    primary key (salesman_no) ,
    check (salesman_no like 'S%'),
    CHECK (Sal_amt > 0),
    CHECK (Tgt_to_get > 0)
);
	select * from db1.salesman_master;
	INSERT INTO db1.salesman_master (Salesman_no, Salesman_name, Address1, Address2, City, Pincode, State, Sal_amt, Tgt_to_get, Ytd_sales, Remarks)
	VALUES
	('S00001', 'Kiran', 'A/14', 'Worli', 'Bombay', '400002', 'Maharashtra', 3000, 100, 50, 'Good'),
	('S00002', 'Manish', '65', 'Nariman', 'Bombay', '400001', 'Maharashtra', 3000, 200, 100, 'Good'),
	('S00003', 'Ravi', 'P-7', 'Bandra', 'Bombay', '400032', 'Maharashtra', 3000, 200, 100, 'Good'),
	('S00004', 'Aashish', 'A/5', 'Juhu', 'Bombay', '400044', 'Maharashtra', 3500, 200, 150, 'Good');

CREATE TABLE db1.sale_order (
    order_no varchar(6),
    order_date DATE ,
    Client_no varchar(6),
    Dely_Addr varchar(25),
    Salesman_no varchar(6),
    Dely_type CHAR(1) Default 'F',
    Billed_yn CHAR(1),
    Dely_date DATE ,
    Order_status varchar(10) ,
    primary key (order_no) ,
		check (order_no like 'O%'),
	check (Dely_type='P'OR Dely_type='F'),
    check (Dely_date >= order_date),
    check ((Order_status = 'In Process') OR (Order_status = 'Fulfilled') OR (Order_status = 'Back Order')OR (Order_status = 'Cancelled')),
    FOREIGN KEY (Client_no) REFERENCES db1.client_master(Client_No),
    FOREIGN KEY (Salesman_no) REFERENCES db1.salesman_master(salesman_no) 
    );
    
	INSERT INTO db1.sale_order (order_no, order_date, Client_no, Dely_type, Billed_yn, Salesman_no, Dely_date, Order_status)
VALUES 
('O19001', '1996-01-12', 'C00001', 'F', 'N', 'S00001', '1996-01-20', 'In Process'),
('O19002', '1996-01-25', 'C00002', 'P', 'N', 'S00002', '1996-01-27', 'Cancelled'),
('O46865', '1996-02-18', 'C00003', 'F', 'Y', 'S00003', '1996-02-20', 'Fulfilled'),
('O19003', '1996-04-03', 'C00001', 'F', 'Y', 'S00001', '1996-04-07', 'Fulfilled'),
('O46866', '1996-05-20', 'C00004', 'P', 'N', 'S00002', '1996-05-22', 'Cancelled'),
('O19008', '1996-05-24', 'C00005', 'F', 'N', 'S00004', '1996-05-26', 'In Process');


	SELECT * FROM db1.sale_order;
delete FROM db1.sale_order_details;
CREATE TABLE db1.sale_order_details(
	order_no varchar(6),
    Product_no varchar(6),
    Qty_ordered Numeric(8),
    Qty_disp Numeric(8),
	Product_rate Numeric(10,2),
    PRIMARY KEY (order_no , Product_no),
    FOREIGN KEY (order_no) REFERENCES db1.sale_order(order_no),
     FOREIGN KEY (Product_no) REFERENCES db1.product_master(Product_no)
);
select * from db1.client_master ;
 select * from db1.product_master ;
 select * from db1.sale_order;
 select * from db1.salesman_master;
select * from db1.sale_order_details;
	INSERT INTO db1.sale_order_details
			VALUES 
				('O19001', 'P00001', 4, 4, 525),
				('O19002', 'P00001', 10, 0, 525),
				('O46865', 'P07868', 3, 3, 3150),
				('O46865', 'P00001', 10, 10, 525),
				('O19003', 'P03453', 2, 2, 1050),
				('O46866', 'P07965', 1, 1, 8400),
				('O19008', 'P00001', 10, 5, 525);
	

-- a):- Find out the clients who stay in a city whose second letter is ‘a’.
		SELECT * FROM db1.client_master 
			WHERE NAME like "_a%";
		

-- b) Find out the clients who stay in a city whose second letter is ‘a’. 
		SELECT * FROM db1.client_master 
			WHERE City LIKE "_a%";


-- c) Find the list of all clients who stay in ‘Bombay’ or ‘Delhi’.
		SELECT *FROM db1.client_master
			WHERE CITY LIKE "Bombay" OR "Delhi";


-- d) Print the list of clients whose bal_due is greater than value 10000.
             select * from db1.client_master 
             where (Bal_due >=10000);


-- e) Print the information from sales_order table for order placed in the month of January.
	    select * from db1.sale_order 
        where (order_date like '%-_1-%');


-- f) Display the order information for client_no ‘C00001’ and ‘C00002’.
       select * from db1.sale_order
       where  (Client_no='C00001' or Client_no='C00002');
       
       
-- g) Find products whose selling price is greater than 2000 and less than or equal to 5000.
         select * from db1.product_master where (Sell_Price>2000 and Sell_Price<=5000);


-- h) Find products whose selling price is more than 1500. Calculate a new selling price as, original selling price * .15. Rename the new column in the
-- above query as new_price.
	SELECT Product_no , Sell_price * .15 AS "New_price"                            
	FROM db1.product_master 
    where (Sell_price > 1500  );


-- i) List the names, city and state of clients who are not in the state of ‘Maharashtra’.
     select Name,City,State 
     from db1.client_master 
     where (State not like 'Maharashtra');


-- j) Count the total number of orders.
      select count(order_no) from db1.sale_order ;

-- k) Calculate the average price of all the products.
	SELECT avg(Cost_price) from db1.product_master;


-- l) Determine the maximum and minimum product prices.
-- Rename the output as max_price and min_price respectively.
		SELECT min(Cost_price) AS "min_price" , max(Cost_price) AS "max_price" from db1.product_master ;


 -- m) Count the number of products having price greater than or equal to 1500.
   select count(Product_no) from db1.product_master where (Sell_price>=1500);


-- n) Find all the products whose qty_no_nahd is less than the recorder level. 
      select * from db1.product_master where (Qty_on_hand < Recorder_lvl);


-- 4 date manipulation
-- a) Display the order number and day on which clients placed their order.
	select order_no ,order_date, dayname(order_date) 
		from db1.sale_order ;
			

 -- b) Display the month (in alphabets) and date when the order must be delivered.       
SELECT order_date AS "Ordered when : " ,day(Dely_date),  
   month(Dely_date),monthname(Dely_date)
			FROM db1.sale_order
				ORDER BY (Dely_date);


-- c) Display the order_date in the format ‘DD-Month-yy’. e.g. 12-February-96.
SELECT date_format(ORDER_DATE,'%D-%M-%Y') AS 'Formatted DATE' FROM db1.sale_order;


-- d) Find the date, 15 days after today’s date.
	SELECT date_add(CURDATE() ,INTERVAL 15 DAY)	AS "date after 15 days";
    
-- e) Find the number of days elapsed between today’s date and the delivery date of the orders placed by the clients.
SELECT order_no,dely_date, datediff(CURRENT_DATE() , dely_date ) AS "CLIENTS" from sale_order;


-- 5 having and group by 
-- a) Print the description and total qty sold for each product.
SELECT p.Product_no, p.Description, SUM(s.Qty_disp) AS total_qty_sold
FROM db1.product_master p
LEFT JOIN db1.sale_order_details s ON p.Product_no = s.Product_no
GROUP BY p.Product_no, p.Description;

-- b) Find the value of each product sold.
SELECT s.Product_no, SUM(s.Qty_disp * p.Sell_price) AS total_value_sold
FROM db1.sale_order_details s
INNER JOIN db1.product_master p ON s.Product_no = p.Product_no
GROUP BY s.Product_no;

-- c) Calculate the average qty sold for each client that has a maximum order value of 15000.00.
select * from db1.sale_order;
SELECT so.Client_no, AVG(sod.Qty_ordered) AS avg_qty_sold
FROM db1.sale_order so
INNER JOIN db1.sale_order_details sod ON so.order_no = sod.order_no
WHERE so.Billed_yn = 'Y' AND so.Bal_due <= 15000
GROUP BY so.Client_no;

-- d) Find out the sum total of all the billed orders for the month of January.
SELECT SUM(sell_price * Qty_disp) AS total_value
FROM db1.sale_order_details sod
INNER JOIN db1.sale_order so ON sod.order_no = so.order_no
WHERE EXTRACT(MONTH FROM so.order_date) = 1 AND so.Billed_yn = 'Y';

-- 6) Exercise on Joins and Correlation: 
-- a) Find out the products, which have been sold to ‘Ivan Bayross’.
SELECT sod.Product_no, p.Description
FROM db1.sale_order_details sod
JOIN db1.sale_order so ON sod.order_no = so.order_no
JOIN db1.Client_master c ON so.Client_no = c.Client_No
JOIN db1.product_master p ON sod.Product_no = p.Product_no
WHERE c.Name = 'Ivan Bayross';

-- b) Find out the products and their quantities that will have to be delivered in the current month.
SELECT sod.Product_no, p.Description, sod.Qty_ordered
FROM db1.sale_order_details sod 
INNER JOIN db1.product_master p 
ON sod.Product_no = p.Product_no 
INNER JOIN db1.sale_order so 
ON sod.order_no = so.order_no
WHERE EXTRACT(MONTH FROM so.Dely_date) = EXTRACT(MONTH FROM sysdate());

-- c) Find the product_no and description of constantly sold i.e. rapidly moving products.
SELECT p.Product_no, p.Description
FROM db1.product_master p
JOIN db1.sale_order_details sod ON p.Product_no = sod.Product_no
GROUP BY p.Product_no, p.Description
HAVING COUNT(sod.Product_no) > 1;

-- d) Find the names of clients who have purchased 'CD Drive'.
SELECT c.Name
FROM db1.Client_master c
JOIN db1.sale_order so ON c.Client_No = so.Client_no
JOIN db1.sale_order_details sod ON so.order_no = sod.order_no
JOIN db1.product_master p ON sod.Product_no = p.Product_no
WHERE p.Description = 'CD Drive';

-- e) List the product_no and order_no of customers having qty_ordered less than 5 from the sales_order_details table for the product ‘1.44 Floppies’.
SELECT sod.Product_no, sod.order_no
FROM db1.sale_order_details sod
JOIN db1.product_master p ON sod.Product_no = p.Product_no
WHERE p.Description = '1.44 Floppies' AND sod.Qty_ordered < 5;

-- f) Find the products and their quantities for the orders placed by 'Ivan Bayross' and 'Vandana Saitwal'.
SELECT sod.Product_no, p.Description, sod.Qty_ordered
FROM db1.sale_order_details sod
JOIN db1.sale_order so ON sod.order_no = so.order_no
JOIN db1.Client_master c ON so.Client_no = c.Client_No
JOIN db1.product_master p ON sod.Product_no = p.Product_no
WHERE c.Name IN ('Ivan Bayross', 'Vandana Saitwal');

-- g) Find the products and their quantities for the orders placed by client_no ‘C00001’ and ‘C00002’.
SELECT sod.Product_no, p.Description, sod.Qty_ordered
FROM db1.sale_order_details sod
JOIN db1.sale_order so ON sod.order_no = so.order_no
JOIN db1.Client_master c ON so.Client_no = c.Client_No
JOIN db1.product_master p ON sod.Product_no = p.Product_no
WHERE c.Client_No IN ('C00001', 'C00002');


-- 7) Exercise on Subqueries:
-- a) Find the product_no and description of non-moving products i.e. products not being sold.

SELECT Product_no, Description
FROM db1.product_master
WHERE Product_no NOT IN (
    SELECT DISTINCT Product_no
    FROM db1.sale_order_details
);



-- b) Find the customer name, address1, address2, city and pin code for the client who has placed order no ‘O19001’.

SELECT Name, Address1, Address2, City, Pincode
FROM db1.Client_master
WHERE Client_No = (
    SELECT Client_no
    FROM db1.sale_order
    WHERE order_no = 'O19001'
);




-- c) Find the client names who have placed orders before the month of May’96.

SELECT Name
FROM db1.Client_master
WHERE Client_No IN (
    SELECT DISTINCT so.Client_no
    FROM db1.sale_order so
    WHERE EXTRACT(MONTH FROM so.order_date) < 5 AND EXTRACT(YEAR FROM so.order_date) = 1996
);



-- d) Find out if the product ‘1.44 Drive’ has been ordered by any client and print the clint_no, name to whom it was sold.
SELECT Client_no, Name 
FROM db1.Client_master
WHERE Client_no IN (
    SELECT DISTINCT so.Client_no
    FROM db1.sale_order_details sod
    JOIN db1.product_master p ON sod.Product_no = p.Product_no
    JOIN db1.sale_order so ON sod.order_no = so.order_no
    WHERE p.Description = '1.44 Drive'
);


-- e) Find the names of clients who have placed orders worth Rs.10000 or more.
SELECT Name
FROM db1.Client_master
WHERE Client_No IN (
    SELECT DISTINCT so.Client_no
    FROM db1.sale_order so
    JOIN db1.sale_order_details sod ON so.order_no = sod.order_no
    JOIN db1.product_master p ON sod.Product_no = p.Product_no
    WHERE sod.Qty_ordered * p.Sell_price >= 10000
);

-- 8) Exercise on Constructing Sentences with data:
-- a) Print information from product_master, sales_order_detail tables in the following format for all the records: {Description} worth Rs. {total sales for the product} was sold.

SELECT p.Description, SUM(sod.Qty_ordered * sod.Product_rate) AS total_sales
FROM db1.product_master p
JOIN db1.sale_order_details sod ON p.Product_no = sod.Product_no
GROUP BY p.Description;


-- b) Print information from product_master, sales_order_detail tables in the following format for all the records:
-- {Description} worth Rs. {total sales for the product} was ordered in the month of {order_date in month format}.

SELECT p.Description,
       SUM(sod.Qty_ordered * sod.Product_rate) AS total_sales,
       EXTRACT(MONTH FROM so.order_date) AS order_month
FROM db1.product_master p
JOIN db1.sale_order_details sod ON p.Product_no = sod.Product_no
JOIN db1.sale_order so ON sod.order_no = so.order_no
GROUP BY p.Description, EXTRACT(MONTH FROM so.order_date);

-- c) Print information from client_master, product_master, sales_order tables in the following format for all the records:
-- {cust_name} has placed order {order_no} on {order_date}.


SELECT c.Name AS cust_name, so.order_no, so.order_date
FROM db1.Client_master c
JOIN db1.sale_order so ON c.Client_No = so.Client_no;



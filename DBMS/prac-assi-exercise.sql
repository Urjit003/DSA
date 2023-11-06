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
	



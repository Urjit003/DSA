create schema Fintech ;
# id , name , initial_balance , type , created_on , notes
use Fintech;
drop table account;
drop table Category;
drop table ledger;
create table Account (
	id int(7) auto_increment, 
    name text NOT NULL,
    type text NOT NULL ,
    created_on datetime  not null ,
    notes text not null ,
    primary key (id) 
);

create table Category (
	id int(7) auto_increment, 
    name text NOT NULL,
    icon text ,
    budget numeric(8,2) ,
    primary key (id)
);
-- key , amount , ac_id , cat_id , transction_type ,payee (in), transfer_to (out)
create table Ledger (
	ledger_id int(7) auto_increment,
    amount numeric(8,2) ,
    account_id int(7) ,
    category_id int(7), 
    transcation_type text(3) not null,
    payee text not null, 
    transfer_to text  not null,
    status text 
    primary key(ledger_id) ,
    foreign key (account_id) REFERENCES fintech.account(id) ,
	foreign key (category_id) REFERENCES fintech.Category(id) 
);

INSERT INTO Account (name, type, created_on, notes) VALUES 
('Checking Account', 'Checking', '2023-01-01 08:30:00', 'Primary checking account'),
('Savings Account', 'Savings', '2023-01-01 09:00:00', 'Primary savings account'),
('Credit Card', 'Credit', '2023-01-01 10:15:00', 'Main credit card'),
('Business Account', 'Checking', '2023-01-01 11:45:00', 'Business checking account'),
('Investment Account', 'Investment', '2023-01-01 12:30:00', 'Stock investments');

INSERT INTO Category (name, icon, budget) VALUES 
('Groceries', 'groceries_icon.png', 500.00),
('Utilities', 'utilities_icon.png', 300.00),
('Entertainment', 'entertainment_icon.png', 200.00),
('Rent', 'rent_icon.png', 1200.00),
('Travel', 'travel_icon.png', 800.00);

INSERT INTO Ledger (amount, account_id, category_id, transcation_type, payee, transfer_to) VALUES 
(150.00, 1, 1, 'in', 'Grocery Store', 'N/A'),
(75.00, 1, 2, 'out', 'Electric Company', 'N/A'),
(50.00, 1, 3, 'out', 'Movie Theater', 'N/A'),
(1200.00, 4, 4, 'out', 'Landlord', 'N/A'),
(300.00, 2, 2, 'in', 'Gas Company', 'N/A'),
(150.00, 3, 1, 'out', 'Supermarket', 'N/A'),
(600.00, 1, 5, 'out', 'Airline', 'N/A'),
(100.00, 5, 3, 'in', 'Concert Venue', 'N/A'),
(500.00, 2, 1, 'out', 'Grocery Store', 'N/A'),
(700.00, 1, 5, 'in', 'Hotel', 'N/A');

select * from ledger;

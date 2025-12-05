-- REMOVE LATER
DROP TABLE IF EXISTS PATRONS;
DROP TABLE IF EXISTS LIBRARIANS;
DROP TABLE IF EXISTS CATALOGUE;
DROP TABLE IF EXISTS LOANS;
DROP TABLE IF EXISTS HOLDS;

-- Table Creations

CREATE TABLE PATRONS (
    card_number INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT NOT NULL UNIQUE,
    pin int NOT NULL,
    numLoans int NOT NULL
);


CREATE TABLE LIBRARIANS (
    lid INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL UNIQUE,
    email TEXT  NOT NULL,
    pin int NOT NULL
);


-- Catalogue table contains NULL VALUES,
-- Only other solutions : Create many tables, which will cause redundancy
-- Use base class and foreign key : Will cause more time to retrieve all necessary data

CREATE TABLE CATALOGUE (
    cid INTEGER PRIMARY KEY AUTOINCREMENT,
    author TEXT NOT NULL,
    title TEXT NOT NULL,
    publish_year  INT NOT NULL,
    status BOOLEAN,
    condition TEXT NOT NULL,
    format TEXT NOT NULL,
    quantity  INT NOT NULL,
    dewey_number TEXT,
    isbn TEXT,
    issue_number INT,
    genre TEXT,
    rating TEXT,
    publication DATE
);


CREATE TABLE LOANS (
    due_date DATE NOT NULL,
    PATRON_ID int,
    ITEM_ID int,
    PRIMARY KEY(PATRON_ID,  ITEM_ID),
    FOREIGN KEY (PATRON_ID) REFERENCES PATRONS(card_number),
    FOREIGN KEY (ITEM_ID) REFERENCES CATALOGUE(cid)
);


-- Each holds row  will contain a cardNumber, and a CatalogueItem


CREATE TABLE HOLDS (
    position int NOT NULL,
    PATRON_ID int,
    ITEM_ID int,
    FOREIGN KEY (PATRON_ID) REFERENCES PATRONS(card_number),
    FOREIGN KEY (ITEM_ID) REFERENCES CATALOGUE(cid)
);

-- Patrons
INSERT INTO PATRONS (name, email, pin, numLoans)
VALUES
('Leon', 'leon@gmail.com', 0000, 0),
('Chris', 'chris@hotmail.com', 1234, 0),
('Hunk', 'hunk@gmail.com', 2068, 0),
('Albert', 'albert@yahoo.com', 2005, 0),
('Ethan', 'ethan@gmail.com', 1098, 0);

-- Librarians
INSERT INTO LIBRARIANS (name, email, pin)
VALUES
('Liroy', 'Liroy@yahoo.com', 2025);

-- Fictional Books
INSERT INTO CATALOGUE (isbn, title, author, publish_year, condition, format, quantity)
VALUES
('9780385660075', 'The Kite Runner', 'Khaled Hosseini', 2003, 'Good', 'Fiction', 8),
('9780385660076', 'A Thousand Splendid Suns', 'Khaled Hosseini', 2007, 'Like New', 'Fiction', 12),
('9780143128540', 'The Alchemist', 'Paulo Coelho', 1988, 'Good', 'Fiction', 5),
('9780062315007', 'The Catcher in the Rye', 'J.D. Salinger', 1951, 'Fair', 'Fiction', 3),
('9780374533557', 'The Glass Castle', 'Jeannette Walls', 2005, 'Good', 'Fiction', 7);

-- Non-Fictional Books
INSERT INTO CATALOGUE (dewey_number, isbn, title, author, publish_year, condition, format, quantity)
VALUES
('500.23', '9780062316097', 'The Sixth Extinction: An Unnatural History', 'Elizabeth Kolbert', 2014, 'Excellent', 'Non-Fiction', 6),
('973.004', '9780143128540', 'The Alchemist', 'Paulo Coelho', 1988, 'Like New', 'Non-Fiction', 5),
('940.531', '9780062315007', 'The Diary of a Young Girl', 'Anne Frank', 1947, 'Good', 'Non-Fiction', 3),
('973.22', '9780374533557', 'The Glass Castle', 'Jeannette Walls', 2005,  'Fair', 'Non-Fiction', 8),
('000.000', '9780316336339', 'Sapiens: A Brief History of Humankind', 'Yuval Noah Harari', 2011, 'Excellent', 'Non-Fiction', 15);

-- Magazines
INSERT INTO CATALOGUE (issue_number, publication, title, author, publish_year, condition, format, quantity)
VALUES
(24045, '2023-01-01', 'Natural Geography', 'HB Studios', 1996, 'Great', 'Magazine', 1),
(33789, '2024-03-12', 'Culinary Chronicles', 'TastyPress Ltd.', 2008, 'Very Good', 'Magazine', 4),
(98231, '2023-09-28', 'Space Frontier Weekly', 'Orbit Publications', 2019, 'Good', 'Magazine', 2);

-- Movies
INSERT INTO CATALOGUE (genre, rating, title, author, publish_year, condition, format, quantity)
VALUES
('Horror', '14+', 'Black Phone 2', 'Landline Co.', 2025, 'Superb', 'Movie', 5),
('Anime/Action', '16+', 'Demon Slayer: Infinity Arc', 'Ufotable Studios', 2024, 'Excellent', 'Movie', 7),
('Action/Thriller', '18+',  'The Raid', 'XYZ Films', 2011, 'Good', 'Movie', 3);

-- Video Games
INSERT INTO CATALOGUE (genre, rating, title, author, publish_year, condition, format, quantity)
VALUES
('Adventure', '17+', 'A Plague Tale Requiem', 'Focus', 2020, 'Good', 'Video Game', 1),
('Stealth', '17+', 'The Last Of Us', 'Naughty Dogs', 2013, 'Ok', 'Video Game', 1),
('Action', '17+', 'Elden Ring', 'FromSoftware', 2020, 'Excellent', 'Video Game', 2),
('Choice', '18+', 'Dispatch', 'Telltale Games', 2025, 'Poor', 'Video Game', 3);

-- Set them all to available
UPDATE CATALOGUE
SET status=TRUE;

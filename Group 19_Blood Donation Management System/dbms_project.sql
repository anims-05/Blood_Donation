create database dbms_project;
use dbms_project;
create table donor_tb( donor_id int primary key auto_increment, 
name varchar(30),
    address varchar(75),
    contact char(10),
    blood_group_id int,
    doctor_id int,
    qty int);
    
    create table receiver_tb( receiver_id int primary key auto_increment,
    name varchar(30),
    address varchar(75),
    contact char(10),
    blood_group_id int,
    doctor_id int,
    qty int);
    
    create table doctor_tb( doctor_id int primary key auto_increment,
    name varchar(30),
    address varchar(75),
    contact char(10));
    
    create table blood_group_tb(blood_group_id int primary key auto_increment,
    blood_group_name varchar(10),
    qty int);
    

	
    
  
import { Table } from "@/components/ui/table";
import React, { use } from "react";

interface User {
  id: Number;
  name: String;
  email: String;
  phone:String;
}
const UsersPage = async (title: any) => {
  const res = await fetch("https://jsonplaceholder.typicode.com/users");
  const users: User[] = await res.json();
  return (
    <div>
      <Table className="border border-ordered text-black text-2xl" >
        <thead className="border border-ordered  bg-cyan-400">
          <tr className="align-">
            <th>User Name</th>
            <th>User email</th>
            <th>User Phone</th>
          </tr> 

        </thead>
        <tbody>
          {users.map((user) => (
            <tr key={user.id} className="border bg-cyan-100">
              <td>{user.name}</td>
              <td>{user.email}</td>
              <td>{user.phone}</td>
            </tr>
          ))}
        </tbody>
      </Table>
      </div>
  );
};

export default UsersPage;

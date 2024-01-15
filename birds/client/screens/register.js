import React, { useState } from "react";
import {
  View,
  StyleSheet,
  StatusBar,
  Platform,
  TextInput,
  TouchableOpacity,
  Text,
  Alert,
} from "react-native";

function Register({ navigation }) {
  const [firstName, setFirstName] = useState("");
  const [lastName, setLastName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");

 const handleRegister = async () => {
   try {
     const response = await fetch("http://127.0.0.1:5000/register", {
       method: "GET",
       headers: {
         "Content-Type": "application/json",
       },
       body: JSON.stringify({
         fname: firstName,
         lname: lastName,
         email: email,
         password: password,
       }),
     });

     const data = await response.json();

     if (response.ok) {
       Alert.alert("Registration Successful", data.message);
       navigation.navigate("Login");
     } else {
       Alert.alert("Registration Failed", data.message);
     }
   } catch (error) {
     console.error("Error during registration:", error);
   }
 };

  return (
    <View style={styles.container}>
      <Text
        style={styles.linkLogin}
        onPress={() => navigation.navigate("Login")}
      >
        You have an account?
      </Text>
      <TextInput
        style={styles.input}
        placeholder="First name"
        textContentType="name"
        placeholderTextColor={"white"}
        value={firstName}
        onChangeText={(text) => setFirstName(text)}
      />
      <TextInput
        style={styles.input}
        placeholder="Last name"
        textContentType="name"
        placeholderTextColor={"white"}
        value={lastName}
        onChangeText={(text) => setLastName(text)}
      />
      <TextInput
        style={styles.input}
        placeholder="Email name"
        textContentType="emailAddress"
        placeholderTextColor={"white"}
        value={email}
        onChangeText={(text) => setEmail(text)}
      />
      <TextInput
        style={styles.input}
        placeholder="Password"
        textContentType="password"
        placeholderTextColor={"white"}
        value={password}
        onChangeText={(text) => setPassword(text)}
      />
      <TouchableOpacity style={styles.submitButton} onPress={handleRegister}>
        <Text>Submit</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "#00010D",
    alignItems: "center",
    justifyContent: "center",
  },
  input: {
    height: 40,
    margin: 20,
    borderWidth: 1,
    padding: 10,
    width: "70%",
    borderColor: "white",
    borderRadius: 50,
    fontSize: 16,
    color: "white",
  },
  submitButton: {
    backgroundColor: "gold",
    padding: 10,
    alignItems: "center",
    borderRadius: 50,
  },
  linkLogin: {
    color: "blue",
  },
});

export default Register;

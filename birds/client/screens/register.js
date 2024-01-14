
  import React, { useState } from "react";
  import {
    View,
    StyleSheet,
    StatusBar,
    Platform,
    TextInput,
    TouchableOpacity,
    Text,
  } from "react-native";

  function Register({ navigation }) {
    const [firstName, setFirstName] = useState("Gosho");
    const [lastName, setLastName] = useState("Ivanov");
    const [email, setEmail] = useState("gosho@gmail.com");
    const [password, setPassword] = useState("pass1234");
    

    return (
      <View style={styles.container}>
        <Text
          style={styles.linkLogin}
          onPress={() => navigation.navigate("Login")}
        >
          You have an acount?
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
        <TouchableOpacity
          style={styles.submitButton}
          onPress={() => navigation.navigate("Home")}
        >
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
      justifyContent:"center"
    },
    input: {
      height: 40,
      margin: 20,
      borderWidth: 1,
      padding: 10,
      width: "70%",
      borderColor: "white",
      borderRadius:50,
      fontSize:16,
      color:"white"
    },
    submitButton: {
      backgroundColor: "gold",
      padding: 10,
      alignItems: "center",
      borderRadius: 50,
    },
    linkLogin:{
      color:"blue",
      
    }
  });

  export default Register;
